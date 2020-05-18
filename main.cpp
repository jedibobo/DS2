#include "pavement.cpp"
#include "park.cpp"
#include <vector>
#include<string>
#include <iomanip>
#include <fstream>    // file stream
#include <sstream>    // string stream
#include "functions.h"

int read_line;
int main()
{	
    //cyh
    
    ParkingLot<Car> p;
    tempParkingLot<Car> tp;
    Pavement<Car> p1;
    Car c, co, ca;
    string car_label;
    char filename[256];
    bool check, checkp, flag;
    L1:cout << "请选择要执行的操作" << endl;
    cout << "1：打印当前停车场" << endl;
    cout << "2：查询当前停车场" << endl;
    cout << "3：车辆驶入" << endl;
    cout << "4：车辆驶离" << endl;
    cout << "输入其他任意键退出系统" << endl;
    int choice; cin >> choice;
    //////////
    switch (choice) 
    {
    case 1:
    {
        system("cls");
        p.Print_park();
        p1.Print_pavement();//
        goto L1;
    }
    case 2:
    {
        system("cls");
        //p1.getstate();
        p.check();
        p1.check();
        goto L1;
    }
       
    case 3:
    {
        cout << "0是手动输入，1是从文件中读取" << endl;
        cin >> flag;
        if (!flag)
        {
            cout << "请输入车牌号" << endl;
            cin >> c.Plate;
            check = p.Push(c);
            if (check == false)
            {
                checkp = p1.Push(c);
                if (checkp == false) {
                    cout << "请重新选择操作" << endl;
                    goto L1;
                }
                else {
                    cout << "请在便道等待" << endl;
                    goto L1;
                }
            }
            else
            {
                cout << "入库成功" << endl;
                goto L1;
            }
        }
        else
        {
            string  strFileName = "fakedata.csv";   //【0】文件名
            fstream file;                                     //【1】声明一个文件输入输出流对象
            file.open(strFileName.c_str(), std::ios::in);           //【2】以读文件的方式打开文件
            if (!file.is_open())
            {
                std::cout << "【NOTICE】文件读取失败" << std::endl;
                std::system("pause");
            }
            else
            {
                std::cout << "【NOTICE】文件读取成功" << std::endl;
                std::system("pause");

            }
            system("cls");
            string strTemp;
            vector<string> strLinesBuffer;          //【1】以行的形式存储CSV文件读入的内容
            vector<string> strAll;                       //【2】以单个字段的形式存储CSV文件中所有的内容
            vector<std::vector<string>> strTable;                //【3】存储表格中的内容
            string line;
            int num_cars = 0;
            while (1)
            {
                std::cout << "输入想要读取的车辆个数，输入0退出" << std::endl;
                std::cin >> num_cars;
                read_line += num_cars;
                if (num_cars == 0) { system("cls"); goto L1; }
                strLinesBuffer.push_back(strTemp);
                std::cout << strTemp << std::endl;
                char* tmpString;
                tmpString = strtok((char*)strTemp.c_str(), ";");
                int count = 0;
                while (getline(file, line) && count < num_cars)   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
                {
                    istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
                    vector<string> fields; //声明一个字符串向量
                    string field;
                    while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
                    {
                        fields.push_back(field); //将刚刚读取的字符串添加到向量fields中

                    }
                    string car_label = fields[0]; //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
                    string in_time = fields[1];
                    string out_time = fields[2];
                    std::cout << setw(9) << setfill(' ')<<car_label << "    入库时间为:"<<setw(6) << setfill('0')<<in_time<<"    ";
                    int x, y;
                    str2int(x,in_time);
                    str2int(y, out_time);
                    //cout << "in_time= " << in_time<< "  " << "out_time= " << out_time <<  endl;
                    count += 1;
                    c.Plate = car_label;
                    c.In = x;
                    c.Out = y;
                    check = p.Push(c);
                    if (check == false)
                    {
                        checkp = p1.Push(c);
                        if (checkp == false) {
                            cout << "请重新选择操作" << endl;
                        }
                        else {
                            cout << "请在便道等待" << endl;
                        }
                    }
                    else
                    {
                        cout << "入库成功" << endl;
                    }
                }
                cout << endl;

            }
            std::cout << "【NOTICE】已按照要求的数量读取并写入。" << std::endl;
        }
    }
    case 4:
    {
        system("cls");
        cout << "请输入车牌号,all全部清空停车场" << endl;
        string out;//车辆出的车牌号或者全部清空标识符
        cin >> out;
        if (out == "all")
        {
            p.Clear();
            while (!p1.IsEmpty())
            {
                if (!p.IsFull())
                {
                    p1.Pop(ca);
                    p.Push(ca);
                }
                else
                    break;
            }
            system("cls");
            goto L1;
        }
        else
        {
            co.Plate=out;
            //p.Pop1(co);//这里需要一个根据车牌查找的函数
            if (p.Pop1(co))
            {
                cout << "停车费用为：" << parking_cost(co)<<endl;
            }
            else
            {
                cout << co.Plate << endl;
            }
            if (!p1.IsEmpty())
            {
                p1.Pop(ca);
                p.Push(ca);
            }
            std::system("pause");
            system("cls");
            goto L1;
            
        }
    }
    default:
        return 0;
    }
	return 0;
}
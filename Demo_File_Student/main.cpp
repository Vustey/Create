#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<list>
using namespace std;
class Object{
public:
    string nameobj;
    float point;
    Object readoneObject(ifstream &File){
        Object obj;
        getline(File,obj.nameobj,'-');
        File>>obj.point;
        return obj;
    }
};
class Student{
public:
    string name;
    string id;
    string birthday;
    vector<Object>objList;
    Student readoneStudent(ifstream &File){
        Student st;
        getline(File,st.name,',');
        getline(File,st.id,',');
        getline(File,st.birthday);
        int n;
        File>>n;
        for(int i=0;i<n;i++){
            Object o;
            Object tmp;
            tmp = o.readoneObject(File);
            st.objList.push_back(tmp);
        }
        return st;
    }
    void output() {
        cout << name << " " << id << " " << birthday << endl;
        for(Object object : objList){
            cout<<object.nameobj<<" "<<object.point;
        }
    }
    Student outputAll(ifstream &File){
        list<Student>stuAll;
        while (!File.eof()){
            Student s;
            Student tmp;
            tmp = s.readoneStudent(File);
            stuAll.push_back(tmp);
        }
        for(Student student:stuAll){
            student.output();
        }
    }
};
int main() {
    ifstream Fileint("E:\\DTU\\C++\\Demo_File_Student\\Student",ios_base::in);
    if(Fileint.is_open()){
        cout<<"Mo file thanh cong!!!"<<endl;
        Student s;
        s.outputAll(Fileint);
//        Student tmp = s.readoneStudent(Fileint);
//        tmp.output();
    }else{
        cout<<"Mo file khong thanh cong !!!"<<endl;
    }
    Fileint.close();
    return 0;
}

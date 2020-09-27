#include<bits/stdc++.h>
#define Max 3
using namespace std;
class Course
{
    float Grade;
    float Credits;
    float GradePoints;
public:
    void GradeCalculate(float temp);
    void SetGrade(float TempGrade)
    {
        Grade=TempGrade;
    }
    void SetCredits()
    {
        cin>>Credits;
    }
    void SetGradePoints(float tempgradepoints)
    {
        GradePoints=tempgradepoints;
    }
    float GetGrade()
    {
        return Grade;
    }
    float GetCredits()
    {
        return Credits;
    }
    float GetGradePoints()
    {
        return GradePoints;
    }
};

class Student
{
    int StudentID;
    float CGPA;
    float TemporaryCGPA;
    Course NumberofCourse[Max];
public:
    void InsertStudentInformation(int Serial,int StudentNumber);
    void CalculateCGPA();
    void SetStudentID(int TemporaryStudentID)
    {
        StudentID=TemporaryStudentID;
    }
    void SetTemporaryCGPA(float tempCGPA)
    {
        TemporaryCGPA=tempCGPA;
    }
    float GetCGPA()
    {
        return CGPA;
    }
    int GetStudentID()
    {
        return StudentID;
    }
    float GetTemporaryCGPA()
    {
        return TemporaryCGPA;
    }

};

void Course:: GradeCalculate(float temp)
{
    SetCredits();
    SetGradePoints((GetCredits()*temp));
}

void Student:: CalculateCGPA()
{
    float SumofCourseGrade=0,SumofCredits=0;
    for(int i=0; i<Max; i++)
    {
        SumofCourseGrade+=NumberofCourse[i].GetGradePoints();
        SumofCredits+=NumberofCourse[i].GetCredits();
    }
    float TempCGPA=SumofCourseGrade/SumofCredits;
    CGPA=TempCGPA;
}

void Student::InsertStudentInformation(int Serial,int StudentNumber)
{
    for(int i=0; i<Max; i++)
    {
        Input:
        cout<<"Course "<<i+1<<":\n";
        cout<<"Grade: ";
        float TempGrade;
        cin>>TempGrade;
        if(TempGrade>4 || TempGrade<0)
        {
           cout<<"Invalid Grade!! Enter Again\n";
           goto Input;
        }
        else
        {
            NumberofCourse[i].SetGrade(TempGrade);
            if(NumberofCourse[i].GetGrade()==4.00)
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(4.00);
            }
            else if(NumberofCourse[i].GetGrade()>=3.75 && NumberofCourse[i].GetGrade()<4.00)
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(3.75);
            }
            else if((NumberofCourse[i].GetGrade()>=3.50 && NumberofCourse[i].GetGrade()<3.75))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(3.50);
            }
            else if((NumberofCourse[i].GetGrade()>=3.25 && NumberofCourse[i].GetGrade()<3.50))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(3.25);
            }
            else if((NumberofCourse[i].GetGrade()>=3.00 && NumberofCourse[i].GetGrade()<3.25))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(3.00);
            }
            else if((NumberofCourse[i].GetGrade()>=2.75 && NumberofCourse[i].GetGrade()<3.00))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(2.75);
            }
            else if((NumberofCourse[i].GetGrade()>=2.50 && NumberofCourse[i].GetGrade()<2.75))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(2.50);
            }
            else if((NumberofCourse[i].GetGrade()>=2.25 && NumberofCourse[i].GetGrade()<2.50))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(2.25);
            }
            else if((NumberofCourse[i].GetGrade()>=2.00 && NumberofCourse[i].GetGrade()<2.25))
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(2.00);
            }
            else if(NumberofCourse[i].GetGrade()<=2.00)
            {
                cout<<"Credits: ";
                NumberofCourse[i].GradeCalculate(0);
            }
        }
    }
    CalculateCGPA();
    if(Serial+1<StudentNumber)
    {
        cout<<"\n";
    }
}

void Merit(Student student[],int StudentNumber)
{
    float *arr=new float[StudentNumber];
    for(int i=0; i<StudentNumber; i++)
    {
        arr[i]=student[i].GetCGPA();
    }

    for(int i=0; i<StudentNumber; i++)
    {
        for(int j=i+1; j<StudentNumber; j++)
        {
            if(arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

    int i=0,j=0;
    while(i<StudentNumber-1)
    {
        if(arr[i]!=arr[i+1])
        {
            student[j].SetTemporaryCGPA(arr[i]);
            j++;
        }
        i++;
    }
    student[j].SetTemporaryCGPA(arr[i]);
    delete [] arr;
}

void StudentResult(Student student[],int StudentRoll,int StudentNumber)
{
    bool check=false;
    for(int i=0; i<StudentNumber; i++)
    {
        if(StudentRoll==student[i].GetStudentID())
        {
            check=true;
            float merit=student[i].GetCGPA();
            cout<<"\nResult:\n"<<"CGPA of the Student ID: "<<StudentRoll<<" is "<<fixed<<setprecision(2)<<student[i].GetCGPA()<<"\n";

            int j=0;
            while(j<StudentNumber || student[j].GetTemporaryCGPA()!=0)
            {
                if(merit==student[j].GetTemporaryCGPA())
                {
                    cout<<"Merit Position: "<<j+1<<'\n';
                    break;
                }
                j++;
            }
            break;
        }
    }
    if(!check)
    {
        cout<<"\nInvalid Student ID!!\n";
    }
}

int main()
{
    cout<<"Enter Students Number: ";
    int StudentNumber;
    cin>>StudentNumber;
    Student *student=new Student[StudentNumber];

    for(int i=0; i<StudentNumber; i++)
    {
        cout<<"Enter Student "<<i+1<<" Student ID: ";
        int TemporarySrudentID;
        cin>>TemporarySrudentID;
        if(i>0 && student[i-1].GetStudentID()==TemporarySrudentID)
        {
            cout<<"Student ID has Already Entered!! Please Enter Another Student ID\n";
            i--;
        }
        else
        {
            student[i].SetStudentID(TemporarySrudentID);
            student[i].InsertStudentInformation(i,StudentNumber);
        }
    }

    Merit(student,StudentNumber);

    cout<<"\nEnter Student ID: ";
    int StudentRoll;
    cin>>StudentRoll;
    StudentResult(student,StudentRoll,StudentNumber);

    delete[] student;
}


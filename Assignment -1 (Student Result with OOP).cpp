#include<bits/stdc++.h>
#define Max 3
using namespace std;
class MeritCalculation;
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
    void SetGradePoints(float TempGradePoints)
    {
        GradePoints=TempGradePoints;
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
    Course NumberofCourse[Max];
public:
    void InsertStudentInformation(int Serial,int StudentNumber);
    void StudentResult(Student student[],MeritCalculation StudentMerit[],int StudentRoll,int StudentNumber);
    void CalculateCGPA();
    bool CheckDuplicateStudentID(Student student[],int Size,int StudentID);
    void SetStudentID(int StudentID)
    {
        this->StudentID=StudentID;
    }
    float GetCGPA()
    {
        return CGPA;
    }
    int GetStudentID()
    {
        return StudentID;
    }

};

class MeritCalculation
{
    int Merit;
public:
    void SetMerit(int Merit)
    {
        this->Merit=Merit;
    }
    int GetMerit()
    {
        return Merit;
    }
    void MeritDeterminer(MeritCalculation StudentMerit[],Student student[],int StudentNumber)
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

        float *ar=new float[StudentNumber];

        int i=0,j=0;
        while(i<StudentNumber-1)
        {
            if(arr[i]!=arr[i+1])
            {
                ar[j]=arr[i];
                j++;
            }
            i++;
        }
        ar[j]=arr[i];

        for(int k=0; k<StudentNumber; k++)
        {
            for(int l=0; l<StudentNumber; l++)
            {
                if(student[k].GetCGPA()==ar[l])
                {
                    StudentMerit[k].SetMerit(l+1);
                }
            }
        }

        delete [] arr;
        delete [] ar;
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

bool Student:: CheckDuplicateStudentID(Student student[],int Size,int StudentID)
{
    bool check=false;
    for(int i=0; i<Size; i++)
    {
        if(student[i].GetStudentID()==StudentID)
        {
            check=true;
            return check;
        }
    }

    return check;
}

void Student:: StudentResult(Student student[],MeritCalculation StudentMerit[],int StudentRoll,int StudentNumber)
{
    bool check=false;
    for(int i=0; i<StudentNumber; i++)
    {
        if(StudentRoll==student[i].GetStudentID())
        {
            check=true;
            cout<<"\nResult:\n"<<"CGPA of the Student ID: "<<StudentRoll<<" is "<<fixed<<setprecision(2)<<student[i].GetCGPA()<<"\n";
            cout<<"Merit Position: "<<StudentMerit[i].GetMerit()<<"\n\n";
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
    Student Object;

    for(int i=0; i<StudentNumber; i++)
    {
input:
        cout<<"Enter Student "<<i+1<<" Student ID: ";
        int StudentID;
        cin>>StudentID;
        if(i>0 && Object.CheckDuplicateStudentID(student,i,StudentID))
        {
            cout<<"Student ID has Already Entered!! Please Enter Another Student ID\n";
            goto input;
        }
        else
        {
            student[i].SetStudentID(StudentID);
            student[i].InsertStudentInformation(i,StudentNumber);
        }
    }

    MeritCalculation *StudentMerit=new MeritCalculation[StudentNumber];
    MeritCalculation Obj;
    Obj.MeritDeterminer(StudentMerit,student,StudentNumber);

    int StudentRoll;
    cout<<"\nEnter Student ID:\n";
    while(cin>>StudentRoll,StudentRoll>0)
    {
        Object.StudentResult(student,StudentMerit,StudentRoll,StudentNumber);
    }

    delete[] student;
    delete[] StudentMerit;
}


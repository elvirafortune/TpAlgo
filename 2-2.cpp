#include<iostream>
#include<vector>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    bool Sovremennik;
    Date() : day(0) , month(0) , year(0) , Sovremennik(false) {}
    Date( int day , int month , int year , bool Sovremennik ) : day(day) , month(month), 
        year(year) , Sovremennik(Sovremennik) {}
   
    bool operator < (Date&);
    bool operator <= (Date&);
    Date& operator = (Date&);
};

bool Date::operator < (Date& A)
{
    if ((this->year < A.year) ||
        (this->year == A.year && this->month < A.month ) ||
        (this->year == A.year && this->month == A.month && this->day < A.day)) 
        return true;
    return false;
}

bool Date::operator <= (Date& A)
{
    if ((this->year > A.year) ||
        (this->year == A.year && this->month > A.month) ||
        (this->year == A.year && this->month == A.month && this->day > A.day)) 
        return false;
    return true;
}

Date& Date::operator = (Date& A)
{
    this->day = A.day;
    this->month = A.month;
    this->year = A.year;
    this->Sovremennik = A.Sovremennik;
    return *this;
}

void heapify (Date *arr, int pos, int n) {
    while (2*pos+1 < n) {
        int t = 2*pos+1;
        if (2*pos+2 < n && arr[t] < arr[2*pos+2] )
        {
            t = 2*pos+2;
        }
        if (arr[pos] < arr[t]) {
            swap(arr[pos], arr[t]);
            pos = t;
        } 
        else break;
    }
}

void heap_make(Date *arr , int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void heap_sort(Date *arr, int n)
{
    heap_make(arr, n);
    while( n > 0 )
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr, 0, n);//
    }
}



int main()
{
    int n = 0; // ���������� �����
    cin >> n;
    Date birth, death;
    int day = 0, month = 0, year = 0;
    Date *mas = new Date[2*n]; // ������ ���, �� � 2 � ������ ��� ����� (�������� � ������)
    int count = 0; //������� ��� � ������� ����� (�������� � ������ ������)

    // �������� ������ ��� �����, ������� �������� 18 � �� ������ ������ 80
    // ������ ���� 18-����� �������� ������ true, � ���� ������ false
    // ����� ����� ���������� � ������������� �� ������ �������� ������, ���� ��������� ���� true, 
    // � ��������, ���� ��������� ���� false, ��� ��� �������� �� �����.
    for ( int i = 0 ; i < n ; i++ )
    {
        // ������� ������ ���� �������� ��������
        cin>> day >> month >> year;
        birth = *new Date(day, month, year+18, true); //��� ����� �� ���� ������� � 18 ���
        // ����� ���� ������
        cin>> day >> month >> year;
        death = *new Date(day, month, year, false);
        if ( death <= birth )
            continue;
        if ( *new Date(birth.day, birth.month, birth.year+62, true) < death )// ���� ��� �� ������ ������ 80 ���
            death = *new Date(birth.day, birth.month, birth.year+62, false);
        
        mas[count] = birth; 
        mas[count + 1] = death;
        count += 2; 
    }
 
    heap_sort(mas, count); // ����������� ���� ��������
  
    int meetings = 0; //������� �������� �������������
    int max_meetings = 0; //������������ �������� �������������
    for ( int i = 0; i < count; i++)
    {
        if (mas[i].Sovremennik == true) // �������� 18 ��� - �����������!
            ++meetings;
        if (mas[i].Sovremennik == false) // ����-�� ����������� 80, ��� �� �����������.
            --meetings;
        // ������ ���������� ������������� ������ �����, ����� �������� ���� ���� ��� ��� ��������� ���� ��������.
        if ((i+1 < count && mas[i] < mas[i+1]) || (i+1 == count))
            max_meetings = max(meetings, max_meetings);
    }
    cout << max_meetings;
  //  system( "pause" );
    return 0;
}
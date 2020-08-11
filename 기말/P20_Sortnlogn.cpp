#include <iostream>

#define S_SIZE 13

using namespace std;

class s_record {
public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);
};

void merge_pass(s_record a[], s_record b[], int n, int s);
void adjust(s_record a[], int t_root, int size);

s_record::s_record() {
    s_id = "00000000";
    name = "None";
    score = 0.0;
}
s_record::s_record(string s1, string s2, double n) {
    s_id = s1;
    name = s2;
    score = n;
}
void quick_sort(s_record a[], int left, int right) {
    s_record pivot, temp;
    int i, j;
    if (left >= right) return;
    i = left;
    j = right + 1;
    pivot = a[left];
    do {
        do {
            i++;
        } while ((i <= right) && (a[i].s_id < pivot.s_id));
        do {
            j--;
        } while (a[j].s_id > pivot.s_id);
        if (i < j)
            swap(a[i], a[j]);
    } while (i < j);
    swap(a[left], a[j]);
    quick_sort(a, left, j - 1);
    quick_sort(a, j + 1, right);
}

void heap_sort(s_record a[], int n) {
    int i;
    s_record b[S_SIZE], temp;

    for (i = 0; i < n; i++)
        b[i + 1] = a[i];
    for (i = n / 2; i > 0; i--)
        adjust(b, i, n);
    for (i = n - 1; i > 0; i--) {
        temp = b[1];
        b[1] = b[i + 1];
        b[i + 1] = temp;
        adjust(b, 1, i);
    }
    a = b;
    for (int i = 0; i < 13; i++) {
        cout << b[i].s_id << " : ";
        cout << b[i].name << " : ";
        cout << b[i].score << endl;
    }
}
void adjust(s_record b[], int t_root, int size) {

    string tmpkey;
    int child;
    s_record tmp;

    tmp = b[t_root];
   
    tmpkey = b[t_root].s_id;
    child = 2 * t_root;

    while (child <= size) {
        if ((child < size) && (b[child].s_id < b[child + 1].s_id))
            child++;
        if (tmpkey > b[child].s_id)
            break;
        else {
            b[child / 2] = b[child];
            child *= 2;
        }
    }
    b[child/2] = tmp;
}


void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while ((i <= n2) && (j <= n4)) 
    { 
        if (a[i].s_id <= a[j].s_id)
            b[k++] = a[i++];
        else 
            b[k++] = a[j++];
    } if (i>n2)
        for (t = j; t <= n4; t++)
            b[t] = a[t];
    else
        for (t = i; t <= n2; t++)
            b[k + t - i] = a[t];
}
void merge_sort(s_record a[], int n)
{
    int s = 1;
    s_record b[S_SIZE];
    while (s < n) {
        merge_pass(a, b, n - 1, s);
        s *= 2;
        merge_pass(b, a, n - 1, s);
        s *= 2;
    }
}
void merge_pass(s_record a[], s_record b[], int n, int s)
{
    int i, j;
    for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    if (i + s <= n)
        merge(a, b, i, i + s - 1, i + s, n);
    else for (j = i; j <= n; j++)
        b[j] = a[j];
}
void show_thelist(s_record a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i].s_id << " : ";
        cout << a[i].name << " : ";
        cout << a[i].score << endl;
    }
}
int main()
{
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
               { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
               { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    int    n = 12;

    //quick_sort(s_list, 0, n-1);
    heap_sort(s_list, n);
    //merge_sort(s_list, n); 

    cout << " < The result of the sorting >" << endl;
    show_thelist(s_list, n);

    return 0;

}
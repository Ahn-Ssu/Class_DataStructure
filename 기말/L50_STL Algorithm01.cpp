/**
 * STL : Alogorithms
 *  vector, list, stack, queue 등을 다룰 때는 멤버 함수를 다루었었는데 
 *  데이터를 다룰 떄 멤버 함수가 아닌 일반 함수로 다룰 수 있는 거 
 * 
 *  P : Iterator 를 통해서 가르키고 다룸 
 * 
 * < Algorithm >
 *      : Container 의 data에 대하여 적용하는 다양한 기능의 함수 
 * 
 * #include <algorithm>
 *  > iterator를 사용하여 data 지정
 *      vector <int>::iterator p;
 * 
 * ex) 
 *  n = count(p1, p2, d); // [p1,p2) 범위에서 d 값을 갖는 원소의 개수 
 *  sort(p1, p2);         // [p1,p2) 범위의 원소를 sort 
 */


//<Sorting>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>

class weight{
    public :
        int kg;
        int gram;
        static bool comp_kg( const weight &s1, const weight &s2){
    if(s1.kg < s2.kg )
        return true;
    return false;
 
}

static bool comp_gram( const weight &s1, const weight & s2){
    if(s1.gram < s2.gram)
        return true;
    return false; 

}
};


viod main(){
    vetor <weight> w_list;

    sort(w_list.begin(), w_list.end(), weight::comp_kg);
    stable_sort(w_list.begin(), w_list.end(), weight::comp_gram);
    
}

/**
 * < Class object 원소의 sorting >
 *  크기 순으로 정렬할때 어떤 것을 기준으로 할 것인지 정해야 함 
 */

class s_record {
    public :
        string s_id;
        string name;
        double score;
        // override
        bool operator<(const s_record&t);
};
// 전형하는 부등호 연산자 오버로딩
bool s_record::operator<(const s_record&t){
    if (s_id< t.s_id)
        return true;
    else
        return false;
}

void main2(){
    vector <s_record> sList = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
                                { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
               { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
               { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };

    sort( sList.begin(), sList.end() );

    for(unsigned int k = 0 ; k < sList.size(); k++)
     cout << sList[k].s_id <<" : " << sList[k].name << " : " << sList[k].score << endl;


}

/**
 * 벡터에서 정렬하는 또 다른 방법 
 * 
 * < 비교 함수를 지정하는 형태의 sorting >
 *  비교 함수를 셋업 
 *  이 방법만의 장점이 있음 
 */

class s_slot {
    public :
        string s_id;
        string name;
        double score;
        string major; // 전공

        static bool comp_sid( const s_slot &s1, const s_slot &s2){
    if(s1.s_id < s2.s_id )
        return true;
    return false;
    // return (s1.s_id < s2.s_id)
}

static bool comp_major( const s_slot &s1, const s_slot & s2){
    if(s1.major < s2.major)
        return true;
    return false; 
    // return (s1.major < s2.major)
}
};



void main3(){
    vector <s_slot> s_list ; // 뒤에 정보 생략 

    sort (s_list.begin(), s_list.end(), s_slot::comp_sid);
    //sort(s_list.begin(), s_list.end(), s_record::comp_major);
}

/**
 * < stable sorting >
 *      Stable sort :
 *          sort 과정에서 key 값의 동일한 원소들은 입력에서 나타난 순서를 유지
 * 
 *          - multiple key를 적용하여 sort하고자 할 때 
 *            secondary key로 sort한 후 primary key 로 stable_sort 수행
 *          // 원래 순서대로 동일 key일때 
 * 
 *      stable_sort() 함수 
 */

// <Stable sort>

void main3(){
    vector <s_slot> s_list ; // 뒤에 정보 생략 

    sort (s_list.begin(), s_list.end(), s_slot::comp_sid);
    stable_sort(s_list.begin(), s_list.end(), s_slot::comp_major);
    // 1번 정렬 학번 순 -> 그리고 1번 정렬을 망쳐놓지 않고 정렬을 학부로 함 
    // second -> primary 
}

#include <vector>
#include <algorithm>
#include <iostream>

class weight{
    public :
        int kg;
        int gram;
        static bool comp_kg( const weight &s1, const weight &s2){
    if(s1.kg < s2.kg )
        return true;
    return false;
 
}

static bool comp_gram( const weight &s1, const weight & s2){
    if(s1.gram < s2.gram)
        return true;
    return false; 

}
}


viod main(){
    vetor <weight> w_list;

    sort(w_list.begin(), w_list.end(), weight::comp_kg);
    stable_sort(w_list.begin(), w_list.end(), weight::comp_gram);

}


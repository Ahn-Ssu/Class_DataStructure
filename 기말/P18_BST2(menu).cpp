#include <iostream>

using namespace std;

class bst_node {
    public :
        string name;
        string callNum;
        string BD;
        string memo;

        bst_node *left, *right;
        bst_node();
        bst_node(string nickName, string number);
        bst_node(string nickName, string number, string day);
        bst_node(string nickName, string number, string day, string other);
        void set_data(string nickName, string number);
        void set_data(string nickName, string number, string day);
        void set_data(string nickName, string number, string day, string other);
};

bst_node::bst_node(){
    bst_node("None","None","None","None");
}
bst_node::bst_node(string nickName, string number){
    bst_node(nickName,number,"None","None");
}
bst_node::bst_node(string nickName, string number, string day){
    bst_node(nickName,number,day,"None");
}
bst_node::bst_node(string nickName, string number, string day, string other){
    name = nickName;
    callNum = number;
    BD = day; 
    memo = other;
}
void bst_node::set_data(string nickName, string number){
    set_data(nickName,number,"None","None");
}
void bst_node::set_data(string nickName, string number, string day){
    set_data(nickName,number,day,"None");
}
void bst_node::set_data(string nickName, string number, string day, string other){
    name = nickName;
    callNum = number;
    BD = day; 
    memo = other;
}

class bst_tree {
        bst_node * root;
        int csize;
    public :
        bst_tree();
        void insert_node(bst_node t);
        bst_node delete_node();
        bool empty();
        int size();
        bst_node search_name(string tid);
        bst_node search_callNum(string numb);
        // or s_record search(string s);

        void show_inorder();
};

void inorder_traverse(bst_node *p);

bst_tree::bst_tree(){
    root = NULL;
    int csize = 0 ; 
}

bst_node bst_tree::search_name(string tid){
    bst_node *p;
    p = root;
    if(root==NULL){
        bst_node tmp;
        tmp.set_data("there","is","no","data"); 
        cout << "The name : " << tid << " dose not exist"<<endl;
        return tmp;
    }

    while(1){
        if(p->name == tid)
         return (*p);
        if(p->name < tid) {
            if(p->right == NULL){
                bst_node tmp;
                tmp.set_data("there","is","no","data");
                cout << "The name : " << tid << " dose not exist"<<endl;
                return tmp;
            }
            else  
                p= p-> right;
            }
            else{
                if(p->left == NULL){
                    bst_node tmp;
                    tmp.set_data("there","is","no","data");
                    cout << "The name : " << tid << "dose not exist"<<endl;
                    return tmp;
                }
                else
                    p = p->left;
            }
    }
}

bst_node bst_tree::search_callNum(string numb){
    bst_node *p;
    p = root;
    if(root==NULL){
        bst_node tmp;
        tmp.set_data("there","is","no","data");
        cout << "The call Number : " << numb << " dose not exist "<<endl;
        return tmp;
    }

    while(1){
        if(p->callNum == numb)
         return (*p);
        if(p->callNum < numb) {
            if(p->right == NULL){
                bst_node tmp;
                tmp.set_data("there","is","no","data");
                cout << "The call number : " << numb << " dose not exist "<<endl;
                return tmp;
            }
            else  
                p= p-> right;
            }
            else{
                if(p->left == NULL){
                    bst_node tmp;
                    tmp.set_data("there","is","no","data");
                    cout << "The call number : " << numb << " dose not exist "<<endl;
                    return tmp;
                }
                else
                    p = p->left;
            }
    }
}

void bst_tree::insert_node(bst_node t){
    bst_node *p;
    bst_node *tmp; // 새로 넣을 임시 공간 

    tmp = new bst_node;
    *tmp = t;
    tmp -> left = NULL;
    tmp -> right = NULL;

    // 비어 있던 경우 
    if(root==NULL){
        root = tmp; 
        return ; 
    }

    //비어 있지않은 경우 
    p = root; 
    while (1) {
         if(p->name == t.name){
             cout << "Insertion Failed : the Key " << t.name << " already exists." << endl; 
             return ; 
         }
         if( (p->name) < t.name ){
             if(p->right == NULL ){
                 p->right = tmp;
                 return ; 
             }
             else 
                p = p->right; 
         }
         else{
             if(p->left == NULL) {
                 p->left = tmp;
                 return; 
             }
             else 
                p = p->left;
         }
    }
}

 void bst_tree::show_inorder(){
     cout<< "\n < LIST > \n"<<endl;
     inorder_traverse(root);
 }

void inorder_traverse(bst_node *p){
    if(p==NULL) 
        return; 
    inorder_traverse(p->left);
    cout << p->name <<" "<< p->callNum ;
    if(p->BD != "None")
     cout <<" "<< p->BD; 
    if(p->memo != "None")
      cout << " "<< p->memo;
    cout << endl;
    inorder_traverse(p->right);
}


void show_memu(){
    cout<< "\n---------- <Menu> ----------";
    cout<<"\n\n1. add new contact";
    cout<<"\n\n2. search contact";
    cout<<"\n\n3. Show all contact";
    cout<<"\n\n4. Quit";
    cout<<"\n\n      Select a command : _ " ; 
}


//새로운 원소 추가 
void memu1(bst_node temp, bst_tree t1){ 
    cout<<"\n\n1. Insert a node\n\n";
    cout<<"Enter name, phoneNumber : ";
    cin >> temp.name >> temp.callNum; 

    int doing ; 
    cout << "Do you want to enter the birthday?   \n(Yes = 1 , no = 0)        : ";
    cin >> doing ; 

    if(doing == 1) {
        cout << "Enter birthday : ";
        cin >> temp.BD;
    }
     
    
    cout << "Do you want to enter the memo?   \n(Yes = 1 , no = 0)        : ";
    cin >> doing ; 

    if(doing ==1){
        cout << "Enter memo : ";
   //     cin >> temp.memo;
        getchar(); 

        char buff[100]; 
        cin.getline(buff, 90);
        temp.memo = buff; 
        

    }

    t1.insert_node(temp);
}

// 원소 조회
void memu2(bst_node temp, bst_tree t1){
    cout<<"\n\n2. search contact";
    cout<<"select search type \n[1. name]\n[2. number]                : ";

    int doing; 
    cin >> doing;

    

    if(doing == 1 ) {
        cout << "Enter the name  : ";
        cin >> temp.name; 
        
       temp = t1.search_name(temp.name);
        cout << temp.name <<" "<< temp.callNum ;
        if(temp.BD != "None")
        cout <<" "<< temp.BD; 
        if(temp.memo != "None")
        cout << " "<< temp.memo;
        cout << endl;
    }
    else if(doing == 2){
        cout << "Enter the number  : ";
        cin >> temp.callNum; 
        temp = t1.search_callNum(temp.callNum);
        cout << temp.name <<" "<< temp.callNum ;
        if(temp.BD != "None")
        cout <<" "<< temp.BD; 
        if(temp.memo != "None")
        cout << " "<< temp.memo;
        cout << endl;
    }
    else
    {
         cout<< "Plz enter right number \n";
    }
    
}
//전체 목록 보기 
void memu3(bst_tree t1){
    t1.show_inorder();
}

int main()
{
    bst_node temp;
    bst_tree t1;
        // 이름 전화번호 생일 메모 
        temp.set_data("안수현", "01051611257", "0411");
        t1.insert_node(temp);
        temp.set_data("김호준교수님", "0542601373", "None","오피스");
        t1.insert_node(temp);
        temp.set_data("정  건", "01012432571", "0524", "17학번");
        t1.insert_node(temp);
        temp.set_data("류광미", "01052245263", "0321","16학번");
        t1.insert_node(temp);
        temp.set_data("태화강", "0542538006");
        t1.insert_node(temp);
        temp.set_data("우리집", "0318381257");
        t1.insert_node(temp);


        show_memu();
        int n;

        while(1){
            cin >> n; 

            if(n==4)
             break; 
            if(n>=1 && n<=3)
            {
                switch(n){
                case 1: memu1(temp, t1); break; 
                case 2: memu2(temp, t1); break;
                case 3: memu3(t1);break;
            }
            }
            else{
                cout << "Input error,  plz enter right number";
                cout<<"\n\n      Select a command : _ " ; 
                continue;
            }
            

            show_memu();
        }
        
        
        return 0;

}
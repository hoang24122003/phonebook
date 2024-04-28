#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

/*
1. Khoi tao Node contact
2. Khoi tao danh sach Contact List (kep)
3. Cac ham thuc hien cong viec
A. Add contact
B. Display contact
C. Search contact
D. Delete contact
E. Update contact
*/

// Update
/*
1. Muon delete -> Nhap dung ca 3 du lieu
2. Sua nhap day du ho ten : DONE
3. Lam not Update contact
4. Sort contact
Xet phan tu cuoi cua ten
Nguyen Duc Anh <- 'h' o cuoi cung
for-> i--; i giam dan den khi nao cham vao dau cach thi no dung lai,
name[i+1] == "A"; A -> ASCII
bien STT int(name[i + 1]);
Tu bien STT thi sap xep
A. Xep theo bang chu cai
B. Xep theo do dai ten string.length();
5. Slide
6. Fix front-end

*/

// Khoi tao Node Contact
class contact
{
public:
    string name;
    string number;
    string mail;
    contact *prev, *next;
    contact(string n, string num, string m)
    {
        name = n;
        number = num;
        mail = m;
        prev = NULL;
        next = NULL;
    };

    friend class contactList;
};

// Khoi tao danh sach Contact List
class contactList
{
public:
    contact *head, *temp, *ptr;

    void addContact();
    void displayContact();
    void searchContact();
    void deleteContact();
    void updateContact();
    void sortContact();
    contact *searchContact2(string name, contact *location);

    contactList()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
    }
};

// A. Add contact
void contactList::addContact()
{
    string name;
    string number;
    string mail;
    bool correctNumber = 0;
    char ans;
    do
    {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap so dien thoai: ";
        while (correctNumber == 0)
        {
            getline(cin, number);
            ptr = head;
            while (ptr != NULL)
            {
                if (number == ptr->number)
                {
                    cout << "So dien thoai ban nhap da bi trung \n Xin hay nhap lai so khac: ";
                    correctNumber = 0;
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL)
                correctNumber = 1;
        }
        correctNumber = 0;
        cout << "Nhap tai khoan mail: ";
        while (correctNumber == 0)
        {
            getline(cin, mail);
            ptr = head;
            while (ptr != NULL)
            {
                if (mail == ptr->mail)
                {
                    cout << "Dia chi mail ban nhap da bi trung \n Xin hay nhap lai dia chi khac: ";
                    correctNumber = 0;
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL)
                correctNumber = 1;
        }
        correctNumber = 0;
        temp = new contact(name, number, mail);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "Ban co muon tiep tuc khong? (y/n): " << endl;
        cin >> ans;
        cin.ignore();
        sortContact();
    } while (ans == 'y');
}

// B. Display contact
void contactList::displayContact()
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << "Ten: " << ptr->name << endl;
        cout << "SDT: " << ptr->number << endl;
        cout << "Mail: " << ptr->mail << endl;
        cout << endl;
        ptr = ptr->next;
    }
}

// C. Search contact
void contactList::searchContact()
{
    string ans;
    do
    {
        cout << "[1]: Tim theo ten" << endl;
        cout << "[2]: Tim theo so dien thoai" << endl;
        cout << "[3]: Tim theo mail" << endl;
        cout << "[4]: Ket thuc tim kiem" << endl;
        getline(cin, ans);
        while (ans != "4" && ans != "3" && ans != "2" && ans != "1")
        {
            cout << "Cu phap da bi sai. Xin moi nhap lai: ";
            getline(cin, ans);
        }
        if (ans == "1")
        {
            cout << "Nhap ten: ";
            string name;
            int numberic = 1;
            bool found = 0;
            getline(cin, name);
            ptr = head;
            cout << "Danh sach nhung danh ba tim thay: " << endl;
            while (ptr != NULL)
            {
                if (name == ptr->name)
                {
                    found = 1;
                    cout << numberic << ")";
                    cout << "Ten: " << ptr->name << endl
                         << "  So dien thoai: " << ptr->number << endl
                         << "  Mail: " << ptr->mail << endl
                         << endl;
                    numberic++;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL && found == 0)
                cout << "Khong tim thay danh ba" << endl;
        }
        else if (ans == "2")
        {
            cout << "Nhap so ";
            string num;
            int numberic = 1;
            bool found = 0;
            getline(cin, num);
            ptr = head;
            cout << "Danh sach nhung danh ba tim thay: " << endl;
            while (ptr != NULL)
            {
                if (num == ptr->number)
                {
                    found = 1;
                    cout << numberic << ")";
                    cout << "Ten: " << ptr->name << endl
                         << "  So dien thoai: " << ptr->number << endl
                         << "  Mail: " << ptr->mail << endl
                         << endl;
                    numberic++;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL && found == 0)
                cout << "Khong tim thay danh ba" << endl;
        }
        else if (ans == "3")
        {
            cout << "Nhap mail: ";
            string mail;
            int numberic = 1;
            bool found = 0;
            getline(cin, mail);
            ptr = head;
            cout << "Danh sach nhung danh ba tim thay: " << endl;
            while (ptr != NULL)
            {
                if (mail == ptr->mail)
                {
                    found = 1;
                    cout << numberic << ")";
                    cout << "Ten: " << ptr->name << endl
                         << "  So dien thoai: " << ptr->number << endl
                         << "  Mail: " << ptr->mail << endl
                         << endl;
                    numberic++;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL && found == 0)
                cout << "Khong tim thay danh ba" << endl;
        }
        else if (ans == "4")
        {
        }
    } while (ans != "4");
}

// Duyet phan tu trong linked list
/*
Tham chieu ten minh can duyet String name;
Location la ptr dau tien ma minh bat dau duyet

*/
contact *contactList::searchContact2(string name, contact *location)
{
    ptr = location;
    while (ptr != NULL)
    {
        if (name == ptr->name)
        {
            cout << "Found!" << endl;
            cout << ptr->name << endl
                 << ptr->number << endl
                 << ptr->mail << endl;
            return ptr; // Return cai dia chi minh can tim trung ten
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
        return NULL;
}
// E. Delete contact
void contactList::deleteContact()
{
    string name; // Nhap ten can xoa
    string ans;  // Nhap cai cau tra loi cua minh
    bool exitBool = 0;
    contact *currentContact = head;
    cout << "Hay nhap ten contact ban muon xoa: ";
    getline(cin, name);
    do
    {
        contact *temp = searchContact2(name, currentContact);
        if (temp == NULL)
        {
            cout << "Khong tim thay contact" << endl;
            exitBool = 1;
            ans = "y";
        }
        else
        {
            cout << "Co phai day la contact ban can xoa?(y/n)";
            getline(cin, ans);
            if (ans == "y")
            {
                currentContact = temp;
                exitBool = 0;
                break;
            }
            currentContact = temp->next;
        }
    } while (ans == "n"); // Tim danh ba muon xoa
    if (exitBool == 0)    // Ham xoa
    {
        if (currentContact == head)
        {
            head = head->next;
            head->prev = NULL;
            delete (currentContact);
            cout << "Contact đã được xóa!\n\n";
        }
        else if (currentContact->next == NULL)
        {
            currentContact->prev->next = NULL;
            delete (currentContact);
            cout << "Contact đã được xóa!\n\n";
        }
        else
        {
            currentContact->prev->next = currentContact->next;
            currentContact->next->prev = currentContact->prev;
            delete (currentContact);
            cout << "Contact đã được xóa!\n\n";
        }
    }
}
// G. Sort contact
void contactList::sortContact()
{
    contact *i, *j;
    for (i = head; i->next != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->name > j->name)
            {
                swap(i->name, j->name);
                swap(i->number, j->number);
                swap(i->mail, j->mail);
            }
        }
}

// H. Update contact
void contactList::updateContact()
{
    string name;
    string ans;
    string newName;
    bool correctNumber = 0;
    bool exitBool = 0;
    contact *currentContact = head;
    cout << "Hay nhap ten contact ban muon update: ";
    getline(cin, name);
    do
    {
        contact *temp = searchContact2(name, currentContact);
        if (temp == NULL)
        {
            cout << "Khong tim thay contact" << endl;
            exitBool = 1;
            break;
        }
        else
        {
            cout << "Co phai day la contact ban can tim?(y/n)";
            getline(cin, ans);
            if (ans == "y")
                break;
            currentContact = temp->next;
        }
    } while (ans == "n");
    if (exitBool == 0)
    {
        cout << "Cap nhat ten moi: ";
        getline(cin, newName);
        currentContact->name = newName;
        cout << "Cap nhat so dien thoai moi: ";
        while (correctNumber == 0)
        {
            getline(cin, newName);
            ptr = head;
            while (ptr != NULL)
            {
                if (newName == ptr->number)
                {
                    cout << "So dien thoai ban nhap da bi trung \n Xin hay nhap lai so khac: ";
                    correctNumber = 0;
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL)
                correctNumber = 1;
        }
        currentContact->number = newName;
        correctNumber = 0;
        cout << "Cap nhat so tai khoan mail moi: ";
        while (correctNumber == 0)
        {
            getline(cin, newName);
            ptr = head;
            while (ptr != NULL)
            {
                if (newName == ptr->mail)
                {
                    cout << "Dia chi mail ban nhap da bi trung \n Xin hay nhap lai dia chi khac: ";
                    correctNumber = 0;
                    break;
                }
                ptr = ptr->next;
            }
            if (ptr == NULL)
                correctNumber = 1;
        }
        currentContact->mail = newName;
        cout << "Da thay doi contact!" << endl;
    }
}

// Phan main
int main()
{
    string name;
    string number;
    string mail;
    contactList phoneBook;
    string selectionInput;
    do
    {
        cout << "-------------- QUAN LY DANH BA ----------------" << endl;
        cout << "[1]: Nhap danh ba" << endl;
        cout << "[2]: Hien thi danh ba" << endl;
        cout << "[3]: Tim kiem danh ba" << endl;
        cout << "[4]: Xoa danh ba" << endl;
        cout << "[5]: Cap nhat danh ba" << endl;
        cout << "[9]: Exit" << endl;
        cout << "Nhap lua chon cua ban: ";
        getline(cin, selectionInput);
        if (selectionInput == "1")
        {
            phoneBook.addContact();
        }
        else if (selectionInput == "2")
        {
            phoneBook.displayContact();
        }
        else if (selectionInput == "3")
        {
            phoneBook.searchContact();
        }
        else if (selectionInput == "4")
        {
            phoneBook.deleteContact();
        }
        else if (selectionInput == "5")
        {
            phoneBook.updateContact();
        }
        else if (selectionInput == "9")
        {
        }
        else
        {
            cout << "Ban da nhap sai menu. Xin moi nhap lai. " << endl;
        }
    } while (selectionInput != "9");
    return 0;
}
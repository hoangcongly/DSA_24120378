/*
Xây dựng ứng dụng nghe nhạc đơn giản, trong đó danh sách bài hát được lưu trữ bằng danh sách liên
kết đôi. Mỗi bài hát có các thông tin sau:
 Mã bài hát
 Tên bài hát
 Tên nghệ sĩ
 Thời lượng
 Tình trạng phát nhạc
Trong danh sách, các mã bài hát là duy nhất và không thay đổi; các bài hát không được trùng nhau
(các bài hát xem là trùng nhau nếu đồng thời tên bài hát và tên nghệ sĩ trùng nhau). Trong một phiên,
chỉ được một bài hát được phát hoặc không có bài nào được phát.
* Yêu cầu
(a) Xây dựng cấu trúc dữ liệu danh sách liên kết đôi.
(b) Viết chức năng thêm thông tin bài hát vào vị trí k bất kỳ trong danh sách liên kết. Mặc định nếu
 k = −1, bài hát sẽ được thêm vào cuối danh sách đơn.
(c) Viết chức năng xóa bài hát dựa theo tên bài hát hoặc theo ca sĩ hoặc xóa toàn bộ danh sách bài
hát.
(d) Viết chức năng sửa thông tin bài hát
(e) Viết chức năng đếm tổng số bài hát trong danh sách, tổng thời lượng trong danh sách.
(f) Viết chức năng tìm kiếm bài hát theo tên bài hát hoặc nghệ sĩ
(g) Viết chức năng sắp xếp các bài hát theo thứ tự tùy chọn.
(h) Xác định bài hát nào đang phát. Cho phép lựa chọn bài đang phát, chọn bài tiếp theo hoặc trở về
bài trước đúng theo thứ tự trong danh sách
(i) Xuất/nhập dữ liệu ra file
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Music
{
    int idSong;
    string nameSong;
    string nameArtist;
    double Duration;
    bool status;
    Music*nextms;
    Music*prevms;
};
struct ListMusic
{
    Music*head;
    Music*tail;
};
Music*CreateMusic(int idsong, string nameSong, string nameArtist, double Duration, bool status)
{
    Music*newMS= new Music();
    newMS->idSong=idsong;
    newMS->nameSong=nameSong;
    newMS->nameArtist=nameArtist;
    newMS->Duration=Duration;
    newMS->status=status;
    newMS->prevms=NULL;
    newMS->nextms=NULL;
    return newMS;
}
ListMusic*CreateListMS()
{
    ListMusic*newListMS= new ListMusic();
    newListMS->head=NULL;
    newListMS->tail=NULL;
    return newListMS;
}
void AddMusic(ListMusic*lms, Music*newMusic, int k)
{
    if(lms->head==NULL)
    {
        lms->head=newMusic;
        lms->tail=newMusic;
        return;
    }
    if(k==-1)
    {
        newMusic->prevms= lms->tail;
        lms->tail->nextms=newMusic;
        lms->tail=newMusic;
        return;
    }
    Music*cur=lms->head;
    for(int i=0; i<k&& cur!=nullptr; i++)
    {
        cur=cur->nextms;
    }
    if(cur==nullptr)
    {
        newMusic->prevms= lms->tail;
        lms->tail->nextms=newMusic;
        lms->tail=newMusic;
        return;
    }
    else
    {
        newMusic->nextms= cur;
        newMusic->prevms=cur->prevms;
        if(cur->prevms!=NULL) cur->prevms->nextms= newMusic;
        cur->prevms=newMusic;
        if(cur==lms->head)
        {
            newMusic->nextms = lms->head;
            lms->head= newMusic;
        }
    }
}
bool checkByName(Music* song, const string& name) {
    return (song->nameSong) == name;
}

bool checkByArtist(Music* song, const string& artist) {
    return (song->nameArtist) == artist;
}
void deleteMusic(ListMusic*lms, bool(*cmp)(Music*, const string&), const string&value)
{
    Music*cur= lms->head;
    while(cur!=NULL)
    {
        if(cmp(cur,value))
        {
            if(cur->prevms!=NULL)
            {
                cur->prevms->nextms=cur->nextms;
            }
            else 
            {
                lms->head=lms->head->nextms;
            }
            if(cur->nextms!=NULL )
            {
                cur->nextms->prevms= cur->prevms;
            }
            else
            {
                lms->tail= cur->prevms;
            }
            delete cur;
            cur= cur->nextms;
        }
    }
}

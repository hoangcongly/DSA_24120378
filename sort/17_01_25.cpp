#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h> // Chạy nhạc trên Windows
#endif

using namespace std;

void hienThiChuCham(const string& str, int delay = 100) {
    for (char c : str) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void veTraiTim() {
    const char* heart[6] = {
        "   ***     ***   ",
        " *****   *****  ",
        "******* ******* ",
        " *************  ",
        "   *********    ",
        "     ***        "
    };

    for (int i = 0; i < 6; i++) {
        cout << heart[i] << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void batNhac() {
#ifdef _WIN32
    PlaySound(TEXT("romantic.wav"), NULL, SND_ASYNC);
#endif
}

int main() {
    system("cls"); // Xóa màn hình (dùng "clear" trên Linux)
    
    batNhac();

    cout << "💖💖💖 Chao em yeu 💖💖💖\n\n";
    this_thread::sleep_for(chrono::seconds(2));

    veTraiTim();
    cout << endl;

    hienThiChuCham("Anh co dieu quan trong muon noi voi em...", 150);
    this_thread::sleep_for(chrono::seconds(2));

    hienThiChuCham("Ngay tu luc gap em, anh da biet em la dinh menh cua doi anh. 💕", 120);
    this_thread::sleep_for(chrono::seconds(2));

    hienThiChuCham("Em dong y lam vo anh nhe? 💍💖", 150);

    string traLoi;
    cout << "\nNhap 'Yes' hoac 'No': ";
    cin >> traLoi;

    if (traLoi == "Yes" || traLoi == "yes") {
        cout << "\n🎉🎉 Oa! Cam on em! Anh yeu em rat nhieu! 💕💍🎊\n";
    } else {
        cout << "\n😢 Anh se cho den khi em noi 'Yes'... 💔\n";
    }

    return 0;
}
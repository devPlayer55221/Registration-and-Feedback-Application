// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include "resource.h"
using namespace std;
// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Feedback Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ButtonProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK StaticProc1(HWND, UINT, WPARAM, LPARAM);



int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_HAND);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_HAND);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;
    //HWND hwndButton;
    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_BORDER,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1300,
        700,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    

    HWND hwndStatic1 = CreateWindow(
        L"STATIC",
        L"Thank You for the Purchase!!",
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | SS_CENTER | WS_BORDER,
        350,
        5,
        400,
        20,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );

    HWND hwndStatic2 = CreateWindow(
        L"STATIC",
        L"Feedback and Registration",
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | SS_CENTER | WS_BORDER,
        350,
        40,
        400,
        20,
        hWnd,
        NULL,
        (HINSTANCE) GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );

    HWND hwndStatic3 = CreateWindow(
        L"STATIC",
        L"Registration Data",
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | SS_CENTER | WS_BORDER,
        100,
        500,
        400,
        100,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );

    HWND hwndStatic4 = CreateWindow(
        L"STATIC",
        L"Feedback Data",
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | SS_CENTER | WS_BORDER,
        800,
        500,
        400,
        100,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );

    HWND hwndEdit1 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL | WS_BORDER,
        250,
        150,
        300,
        30,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );
    HWND hwndEdit2 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL | WS_BORDER,
        250,
        190,
        300,
        30,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );
    HWND hwndEdit3 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL | WS_BORDER,
        250,
        230,
        300,
        30,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );
    HWND hwndEdit4 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL | WS_BORDER,
        250,
        270,
        300,
        30,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );
    HWND hwndEdit5 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL | WS_BORDER,
        250,
        310,
        300,
        30,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );
    HWND hwndEdit6 = CreateWindow(
        L"EDIT",
        NULL,
        WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_CENTER | WS_BORDER,
        800,
        150,
        400,
        200,
        hWnd,
        NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL
    );

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
    

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    HDC hdcStatic1;
    HDC hdcStatic2;
    HDC hdcStatic3;

    TCHAR askname[] = _T("Enter your Name");
    TCHAR askemail[] = _T("Enter your Email ID");
    TCHAR askphone[] = _T("Enter your Phone no.");
    TCHAR askserial[] = _T("Enter your Serial no.");
    TCHAR askorder[] = _T("Enter your Order ID");
    TCHAR askfeedback[] = _T("Please provide feedback");
    HWND hbutton = FindWindowEx(hWnd, NULL, L"BUTTON", L"Submit Data");
    HWND hbutton2 = FindWindowEx(hWnd, NULL, L"BUTTON", L"Submit Feedback");
    HWND hwndstatic = FindWindowEx(hWnd, NULL, L"STATIC", L"Thank You for the Purchase!!");
    HWND hwndstat = FindWindowEx(hWnd, NULL, L"STATIC", L"Registration Data");
    HWND hwndstat2 = FindWindowEx(hWnd, NULL, L"STATIC", L"Feedback and Registration");
    HWND hwndstat3 = FindWindowEx(hWnd, NULL, L"STATIC", L"Feedback Data");
    HWND hedit1 = FindWindowEx(hWnd, NULL, L"EDIT", NULL);
    HWND hedit2 = FindWindowEx(hWnd, hedit1, L"EDIT", NULL);
    HWND hedit3 = FindWindowEx(hWnd, hedit2, L"EDIT", NULL);
    HWND hedit4 = FindWindowEx(hWnd, hedit3, L"EDIT", NULL);
    HWND hedit5 = FindWindowEx(hWnd, hedit4, L"EDIT", NULL);
    HWND hedit6 = FindWindowEx(hWnd, hedit5, L"EDIT", NULL);


    LPDRAWITEMSTRUCT lpdis1;
    LPDRAWITEMSTRUCT lpdis2;

    

    TCHAR buff1[256];
    TCHAR buff2[256];
    TCHAR buff3[256];
    TCHAR buff4[256];
    TCHAR buff5[256];
    TCHAR buff6[256];
    TCHAR nbuff1[256];
    TCHAR nbuff2[256];
    TCHAR nbuff3[256];
    TCHAR nbuff4[256];
    TCHAR nbuff5[256];
    TCHAR nbuff6[256];
    TCHAR finaldata[256];
    TCHAR text1[256];
    TCHAR text2[256];
    TCHAR val1[256] = _T("Submit Data");
    TCHAR val2[256] = _T("Submit Feedback");
    HBRUSH hbru1 = NULL;
    HBRUSH hbru2 = NULL;
    HBRUSH hbru3 = NULL;
    HFONT hfont1;
    HFONT hfont2;
    HFONT hfont3;
    HFONT hfont4;
    hfont1 = CreateFont(0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Bahnschrift"));
    hfont2 = CreateFont(0, 8, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Segoe UI"));
    hfont3 = CreateFont(20, 8, 0, 0, 700, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Helvetica"));
    hfont4 = CreateFont(0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Calibri"));
    SendMessage(hbutton, WM_SETFONT, WPARAM(hfont3), 0);
    SendMessage(hbutton2, WM_SETFONT, WPARAM(hfont3), 0);
    SendMessage(hwndstat2, WM_SETFONT, WPARAM(hfont1), 0);
    SendMessage(hwndstatic, WM_SETFONT, WPARAM(hfont1), 0);
    SendMessage(hwndstat, WM_SETFONT, WPARAM(hfont1), 0);
    SendMessage(hwndstat3, WM_SETFONT, WPARAM(hfont1), 0);
   
    

    HWND hwndButton, hwndButton2;

    switch (message)
    {
        TCHAR msg[32];
        TCHAR val[32];

    
    case WM_CREATE:
        hwndButton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"Submit Data",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_CENTER | BS_OWNERDRAW | WS_BORDER,  // Styles 
            150,         // x position 
            370,         // y position 
            120,        // Button width
            30,        // Button height
            hWnd,     // Parent window
            (HMENU)IDB_BUTTON,       // No menu.
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL
        );      // Pointer not needed.

        hwndButton2 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"Submit Feedback",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_CENTER | BS_OWNERDRAW | WS_BORDER,  // Styles 
            920,         // x position 
            370,         // y position 
            150,        // Button width
            30,        // Button height
            hWnd,     // Parent window
            (HMENU)IDB_BUTTON2,       // No menu.
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL
        );
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SelectObject(hdc, hfont2);
        SetTextColor(hdc, RGB(0, 0, 160));

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        TextOut(hdc, 5, 150, askname, _tcslen(askname));
        TextOut(hdc, 5, 190, askemail, _tcslen(askemail));
        TextOut(hdc, 5, 230, askphone, _tcslen(askphone));
        TextOut(hdc, 5, 270, askserial, _tcslen(askserial));
        TextOut(hdc, 5, 310, askorder, _tcslen(askorder));
        TextOut(hdc, 900, 100, askfeedback, _tcslen(askfeedback));
        
        // End application-specific layout section.

        EndPaint(hWnd, &ps);
        break;

    case WM_CTLCOLOREDIT:
        hdcStatic1 = (HDC)wParam;
        SetTextColor(hdcStatic1, RGB(0, 0, 160));
        if (hbru1 == NULL)
        {
            hbru1 = CreateSolidBrush(RGB(255, 255, 255));
        }
        return (INT_PTR)hbru1;
        break;

    case WM_CTLCOLORSTATIC:
        hdcStatic2 = (HDC) wParam;
        SetTextColor(hdcStatic2, RGB(0, 0, 160));
        if (hbru2 == NULL)
        {
            hbru2 = CreateSolidBrush(RGB(255, 255, 255));
        }
        return (INT_PTR)hbru2;
        break;

    case WM_CTLCOLORBTN:
        hdcStatic3 = (HDC)wParam;
        SetTextColor(hdcStatic3, RGB(0, 0, 160));
        if (hbru3 == NULL)
        {
            hbru3 = CreateSolidBrush(RGB(255, 255, 255));
        }
        return (INT_PTR)hbru3;
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            case IDB_BUTTON:
                switch (HIWORD(wParam))
                {
                    case BN_CLICKED:
                        hdc = BeginPaint(hWnd, &ps);
                        SelectObject(hdc, hfont2);
                        SetTextColor(hdc, RGB(0, 0, 0));
                        SetBkColor(hdc, RGB(255, 255, 0));

                        

                        ShellExecute(NULL, L"open", L"https://www.gmail.com", NULL, NULL, SW_SHOW);
                        
                        
                        SendMessage(hedit1, WM_GETTEXT, sizeof(buff1), LPARAM(buff1));
                        SendMessage(hedit2, WM_GETTEXT, sizeof(buff2), LPARAM(buff2));
                        SendMessage(hedit3, WM_GETTEXT, sizeof(buff3), LPARAM(buff3));
                        SendMessage(hedit4, WM_GETTEXT, sizeof(buff4), LPARAM(buff4));
                        SendMessage(hedit5, WM_GETTEXT, sizeof(buff5), LPARAM(buff5));
                        if (!_tcslen(buff1) || !_tcslen(buff2) || !_tcslen(buff3) || !_tcslen(buff4)
                            || !_tcslen(buff5))
                            break;
                        swprintf_s(nbuff1, _T("[Name = %s]"), buff1);
                        swprintf_s(nbuff2, _T("[Email ID = %s]"), buff2);
                        swprintf_s(nbuff3, _T("[Phone no = %s]"), buff3);
                        swprintf_s(nbuff4, _T("[Serial no = %s]"), buff4);
                        swprintf_s(nbuff5, _T("[Order no = %s]"), buff5);
                        SendMessage(hwndstatic, WM_SETTEXT, NULL, (LPARAM)TEXT("Purchase successful!!"));
                        swprintf_s(finaldata, _T("%s. %s. %s. %s. %s."), nbuff1,nbuff2,nbuff3,nbuff4,nbuff5);
                        SendMessage(hwndstat, WM_SETTEXT, NULL, (LPARAM)(finaldata));
                        OutputDebugString(_T("bn clicked\n"));
                        OutputDebugString(finaldata);

                        TCHAR line1[] = _T("$From = \"<sender address>\"\n$To = \"<receiver address>\"\n$Subject = \"Application Data\"\n$Body = \"");
                        TCHAR line2[] = _T("\"\n$SMTPServer = \"smtp-mail.outlook.com\"\n$SMTPPort = \"587\"\n");
                        TCHAR line3[] = _T("$User = \"user(sender) address\"\n$Pword = ConvertTo-SecureString -String \"<>\" -AsPlainText -Force\n");
                        TCHAR line4[] = _T("$Credential = New-Object -TypeName System.Management.Automation.PSCredential -ArgumentList $User, $Pword\n");
                        TCHAR line5[] = _T("Send-MailMessage -From $From -to $To -Subject $Subject -Body $Body -SmtpServer $SMTPServer -port $SMTPPort -UseSsl -Credential $Credential -DeliveryNotificationOption OnSuccess");
                        TCHAR shellscript[2048];

                        swprintf_s(shellscript, _T("%s%s%s%s%s%s"), line1, finaldata, line2, line3, line4, line5);
                        OutputDebugString(shellscript);

                        TCHAR databuff[] = L"test string to be written";
                        FILE* fp;
                        fopen_s(&fp, "newfile.ps1", "w+");
                        fprintf_s(fp, "%ls%c", shellscript, '\n');
                        fclose(fp);

                        TCHAR toexecute[256] = L"-ExecutionPolicy Bypass -noexit -file newfile.ps1";
                        SHELLEXECUTEINFO ShExecInfo = { 0 };
                        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
                        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
                        ShExecInfo.hwnd = NULL;
                        ShExecInfo.lpVerb = L"open";
                        ShExecInfo.lpFile = L"powershell";
                        ShExecInfo.lpParameters = toexecute;
                        ShExecInfo.lpDirectory = NULL;
                        ShExecInfo.nShow = SW_HIDE;
                        ShExecInfo.hInstApp = NULL;
                        ShellExecuteEx(&ShExecInfo);

                        OutputDebugString(_T("\n"));
                        break;
                }
                break;
            case IDB_BUTTON2:
                switch (HIWORD(wParam))
                {
                    case BN_CLICKED:
                        SendMessage(hedit6, WM_GETTEXT, sizeof(buff6), LPARAM(buff6));
                        if (!_tcslen(buff6))
                            break;
                        swprintf_s(nbuff6, _T("[Feedback = %s]"), buff6);
                        SendMessage(hwndstat3, WM_SETTEXT, NULL, (LPARAM)(nbuff6));
                        OutputDebugString(nbuff6);
                        break;
                }
                break;
        }
        break;

    case WM_DRAWITEM:
        switch ((UINT)wParam)
        {
            case IDB_BUTTON:
                lpdis1 = (LPDRAWITEMSTRUCT)lParam;
                SIZE size1;
                swprintf_s(text1, _T("%s"), val1);
                GetTextExtentPoint32(lpdis1->hDC, text1, _tcslen(text1), &size1);

                SetTextColor(lpdis1->hDC, RGB(0, 0, 160));
                SetBkColor(lpdis1->hDC, RGB(255, 255, 255));

                ExtTextOut(lpdis1->hDC,
                    ((lpdis1->rcItem.right - lpdis1->rcItem.left) - size1.cx) / 2,
                    ((lpdis1->rcItem.bottom - lpdis1->rcItem.top) - size1.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis1->rcItem, text1, _tcslen(text1), NULL);
                
                return TRUE;
            break;

            case IDB_BUTTON2:
                lpdis2 = (LPDRAWITEMSTRUCT)lParam;
                SIZE size2;
               
                swprintf_s(text2, _T("%s"), val2);
                GetTextExtentPoint32(lpdis2->hDC, text2, _tcslen(text2), &size2);

                SetTextColor(lpdis2->hDC, RGB(0, 0, 160));
                SetBkColor(lpdis2->hDC, RGB(255, 255, 255));

                ExtTextOut(lpdis2->hDC,
                    ((lpdis2->rcItem.right - lpdis2->rcItem.left) - size2.cx) / 2,
                    ((lpdis2->rcItem.bottom - lpdis2->rcItem.top) - size2.cy) / 2,
                    ETO_OPAQUE | ETO_CLIPPED, &lpdis2->rcItem, text2, _tcslen(text2), NULL);

                return TRUE;
                break;
        }
        break;

    case WM_CLOSE:
        if (MessageBox(hWnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
        {
            DestroyWindow(hWnd);
        }
        // Else: User canceled. Do nothing.
        return 0;
        break;
    case WM_SYSKEYDOWN:
        swprintf_s(msg, L"WM_SYSKEYDOWN: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_SYSCHAR:
        swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
        OutputDebugString(msg);
        break;

    case WM_SYSKEYUP:
        swprintf_s(msg, L"WM_SYSKEYUP: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_KEYDOWN:
        swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_KEYUP:
        swprintf_s(msg, L"WM_KEYUP: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_CHAR:
        SendMessage(hwndstatic, WM_SETTEXT, NULL, (LPARAM)TEXT("Purchase successful!!"));
        swprintf_s(msg, L"WM_CHAR: %c\n", (wchar_t)wParam);        
        OutputDebugString(msg);
        OutputDebugString(val);
        UpdateWindow(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}
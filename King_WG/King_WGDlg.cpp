
// King_WGDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "King_WG.h"
#include "King_WGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKingWGDlg 对话框



CKingWGDlg::CKingWGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_KING_WG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CKingWGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CKingWGDlg::MSGBOX(string ToDisplay)
{
	MessageBoxA(ToDisplay.c_str(), "XPP Framework Saurik King@ithot.top", MB_OK);
	return;
}

BEGIN_MESSAGE_MAP(CKingWGDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CKingWGDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CKingWGDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKingWGDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CKingWGDlg 消息处理程序

BOOL CKingWGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm* ptm = localtime(&tt);
	if ((ptm->tm_year + 1900) >= 2018 && (ptm->tm_mon + 1) > 1)
	{
		MessageBoxA("Out of date!\nContact king@ithot.top for update.\n联系启动器作者 king@ithot.top 以获取更新", "Please Update!", MB_ICONERROR);
		ExitProcess(-1);
	}
	if (MessageBoxA("未经授权禁止更改本应用\n本应用免费授权给经销商和代理商，作者没收到一毛钱\n由于使用本程序所造成的后果，作者一律不会负责。\n不反对也不鼓励经销商、代理商出售本程序\n本程序仅供学习使用\n请悉知接受条款后继续", "确认表示接受条款", MB_OKCANCEL) == IDCANCEL)
	{
		ExitProcess(-1);
	}
	ofstream("接定制软件king@ithot.top.cpp", ios::out);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CKingWGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CKingWGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CKingWGDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (MessageBoxA("您真的要退出吗？", "退出确认", MB_OKCANCEL) == IDOK)
		CDialog::OnOK();
	else
		return;
}


void CKingWGDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	char filePath[MAX_PATH];

	::SHGetSpecialFolderPath(NULL, filePath, CSIDL_LOCAL_APPDATA, FALSE);

	string XSTR(filePath);

	XSTR += "\\TslGame\\Saved\\Config\\WindowsNoEditor\\Engine.ini";

	ifstream FilePTR(XSTR.c_str(), ios::in);

	if (!FilePTR)
	{
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "未找到配置文件。").detach();
		return;
	}

	FilePTR.close();
	FilePTR.clear();

	DWORD nxpd = 0;

	nxpd = GetPrivateProfileIntA("/script/engine.renderersettings", "grass.DiscardDataOnLoad", 0, XSTR.c_str());

	SetFileAttributes(XSTR.c_str(), FILE_ATTRIBUTE_NORMAL);

	if (nxpd == 0)
	{
		WritePrivateProfileStringA("/script/engine.renderersettings", "grass.DiscardDataOnLoad", "1", XSTR.c_str());
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "已经开启去草").detach();
	}
	else
	{
		WritePrivateProfileStringA("/script/engine.renderersettings", "grass.DiscardDataOnLoad", "0", XSTR.c_str());
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "已经关闭去草").detach();
	}

	SetFileAttributes(XSTR.c_str(), FILE_ATTRIBUTE_READONLY);

	return;
}


void CKingWGDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	char filePath[MAX_PATH];

	::SHGetSpecialFolderPath(NULL, filePath, CSIDL_LOCAL_APPDATA, FALSE);

	string XSTR(filePath);

	XSTR += "\\TslGame\\Saved\\Config\\WindowsNoEditor\\Engine.ini";

	ifstream FilePTR(XSTR.c_str(), ios::in);

	if (!FilePTR)
	{
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "未找到配置文件。").detach();
		return;
	}

	FilePTR.close();
	FilePTR.clear();

	DWORD nxpd = 0;

	nxpd = GetPrivateProfileIntA("/script/engine.renderersettings", "foliage.DiscardDataOnLoad", 0, XSTR.c_str());

	SetFileAttributes(XSTR.c_str(), FILE_ATTRIBUTE_NORMAL);

	if (nxpd == 0)
	{
		WritePrivateProfileStringA("/script/engine.renderersettings", "foliage.DiscardDataOnLoad", "1", XSTR.c_str());
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "已经开启去树").detach();
	}
	else
	{
		WritePrivateProfileStringA("/script/engine.renderersettings", "foliage.DiscardDataOnLoad", "0", XSTR.c_str());
		shared_ptr<CKingWGDlg>NxDlg(new CKingWGDlg);
		thread(&CKingWGDlg::MSGBOX, NxDlg, "已经关闭去树").detach();
	}

	SetFileAttributes(XSTR.c_str(), FILE_ATTRIBUTE_READONLY);

	return;
}

#pragma once

#include <winsock2.h>

namespace Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Run;
	protected: 

	private: System::Windows::Forms::RichTextBox^  LoggerTxtBox;
	private: System::ComponentModel::BackgroundWorker^  bgwMain;
	private: System::Windows::Forms::RichTextBox^  ServerMsgBox;
	private: System::Windows::Forms::TextBox^  ConnectAddrBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Run = (gcnew System::Windows::Forms::Button());
			this->LoggerTxtBox = (gcnew System::Windows::Forms::RichTextBox());
			this->bgwMain = (gcnew System::ComponentModel::BackgroundWorker());
			this->ServerMsgBox = (gcnew System::Windows::Forms::RichTextBox());
			this->ConnectAddrBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Run
			// 
			this->Run->Location = System::Drawing::Point(827, 101);
			this->Run->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(111, 29);
			this->Run->TabIndex = 0;
			this->Run->Text = L"Run!";
			this->Run->UseVisualStyleBackColor = true;
			this->Run->Click += gcnew System::EventHandler(this, &Form1::Run_Click);
			// 
			// LoggerTxtBox
			// 
			this->LoggerTxtBox->Location = System::Drawing::Point(38, 236);
			this->LoggerTxtBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->LoggerTxtBox->Name = L"LoggerTxtBox";
			this->LoggerTxtBox->Size = System::Drawing::Size(900, 375);
			this->LoggerTxtBox->TabIndex = 2;
			this->LoggerTxtBox->Text = L"";
			// 
			// bgwMain
			// 
			this->bgwMain->WorkerReportsProgress = true;
			this->bgwMain->WorkerSupportsCancellation = true;
			this->bgwMain->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::bgwMain_DoWork);
			this->bgwMain->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::bgwMain_ProgressChanged);
			this->bgwMain->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::bgwMain_RunWorkerCompleted);
			// 
			// ServerMsgBox
			// 
			this->ServerMsgBox->Location = System::Drawing::Point(38, 92);
			this->ServerMsgBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ServerMsgBox->Name = L"ServerMsgBox";
			this->ServerMsgBox->Size = System::Drawing::Size(773, 114);
			this->ServerMsgBox->TabIndex = 3;
			this->ServerMsgBox->Text = L"";
			// 
			// ConnectAddrBox
			// 
			this->ConnectAddrBox->Location = System::Drawing::Point(38, 36);
			this->ConnectAddrBox->Name = L"ConnectAddrBox";
			this->ConnectAddrBox->ReadOnly = true;
			this->ConnectAddrBox->Size = System::Drawing::Size(240, 23);
			this->ConnectAddrBox->TabIndex = 4;
			this->ConnectAddrBox->Text = L"127.0.0.1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 15);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Address";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 15);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Response Message";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 217);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Log";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 624);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ConnectAddrBox);
			this->Controls->Add(this->ServerMsgBox);
			this->Controls->Add(this->LoggerTxtBox);
			this->Controls->Add(this->Run);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"MessageServer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: delegate int WriteLineDelgate(System::String^ str);
	public: System::String^ SndMsgStr;
	public: System::String^ ConnectAddr;

	private: System::Void RegisterLogger(System::String^ str){
			LoggerTxtBox->AppendText(System::DateTime::Now.ToString() + " " + str + System::Environment::NewLine);
			LoggerTxtBox->ScrollToCaret();
		}

	private: System::Void ShowErr(int err){
			switch (err) {
				case WSASYSNOTREADY:
					RegisterLogger("WSASYSNOTREADY\n");
					break;
				case WSAVERNOTSUPPORTED:
					RegisterLogger("WSAVERNOTSUPPORTED\n");
					break;
				case WSAEINPROGRESS:
					RegisterLogger("WSAEINPROGRESS\n");
					break;
				case WSAEPROCLIM:
					RegisterLogger("WSAEPROCLIM\n");
					break;
				case WSAEFAULT:
					RegisterLogger("WSAEFAULT\n");
					break;
				default:
					RegisterLogger("Socket is OK! \n");
					break;
			}
		}

	private: System::Void Run_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->bgwMain->IsBusy){
				RegisterLogger("Abort!");
				bgwMain->CancelAsync();
				Run->Text = "Run!";
				WSACleanup();
				//RegisterLogger("BackGroundWorkerMain is BUSY!");
			}else{
				Run->Text = "Abort!";
				SndMsgStr = ServerMsgBox->Text;
				ConnectAddr = ConnectAddrBox->Text;
				RegisterLogger("Wait Connect...");
				this->bgwMain->RunWorkerAsync();
			}
		}

	private: System::Void bgwMain_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			WSADATA wsaData;
			int err = WSAStartup(MAKEWORD(2,0), &wsaData);
			//ShowErr(err);

			//RegisterLogger("Wait Connect...");
			SOCKET sock0 = socket(AF_INET, SOCK_STREAM, 0);

			if (sock0 == INVALID_SOCKET) {
				//RegisterLogger("socket error : " + WSAGetLastError().ToString());
			}

			// Configure Socket
			struct sockaddr_in addr;
			struct sockaddr_in client;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(12345);
			addr.sin_addr.S_un.S_addr = INADDR_ANY;

			// bind
			if (bind(sock0, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
				//RegisterLogger("socket error : " + WSAGetLastError().ToString());
			}

			// start listen
			if (listen(sock0, 5) != 0) {
				//RegisterLogger("socket error : " + WSAGetLastError().ToString());
			}

			while(true){
				int len = sizeof(client);
				SOCKET sock = accept(sock0, (struct sockaddr *)&client, &len);
				if (sock == INVALID_SOCKET) {
					//RegisterLogger("socket error : " + WSAGetLastError().ToString());
					break;
				}

				//System::String^ connection_addr = gcnew String(inet_ntoa(client.sin_addr));
				//RegisterLogger("accepted connection from : " + connection_addr + ", port = " + ntohs(client.sin_port).ToString());
				char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(SndMsgStr);
				unsigned int size = SndMsgStr->Length;
				unsigned int n = send(sock, str, size, 0);
				if (n < 1) {
					//RegisterLogger("socket error : " + WSAGetLastError().ToString());
					break;
				}

				closesocket(sock);
			}
			WSACleanup();
		}
	private: System::Void bgwMain_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			if(this->bgwMain->WorkerSupportsCancellation == true)
            {
                // Cancel the asynchronous operation.
                bgwMain->CancelAsync();
				RegisterLogger("Cancel!");
            }
		}

	private: System::Void bgwMain_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			RegisterLogger("Completed!");
			Run->Text = "Run!";
		}
};
}


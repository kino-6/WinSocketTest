#pragma once

#include <winsock2.h>

namespace Client {

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
	private: System::Windows::Forms::Button^  RunButton;
	private: System::Windows::Forms::RichTextBox^  LoggerTxtBox;
	private: System::Windows::Forms::TextBox^  dstStrBox;

	protected: 

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
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->LoggerTxtBox = (gcnew System::Windows::Forms::RichTextBox());
			this->dstStrBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// RunButton
			// 
			this->RunButton->Location = System::Drawing::Point(279, 42);
			this->RunButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(87, 29);
			this->RunButton->TabIndex = 0;
			this->RunButton->Text = L"Connect";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &Form1::RunButton_Click);
			// 
			// LoggerTxtBox
			// 
			this->LoggerTxtBox->Location = System::Drawing::Point(12, 119);
			this->LoggerTxtBox->Name = L"LoggerTxtBox";
			this->LoggerTxtBox->Size = System::Drawing::Size(717, 293);
			this->LoggerTxtBox->TabIndex = 1;
			this->LoggerTxtBox->Text = L"";
			// 
			// dstStrBox
			// 
			this->dstStrBox->Location = System::Drawing::Point(30, 48);
			this->dstStrBox->Name = L"dstStrBox";
			this->dstStrBox->Size = System::Drawing::Size(227, 23);
			this->dstStrBox->TabIndex = 2;
			this->dstStrBox->Text = L"127.0.0.1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 424);
			this->Controls->Add(this->dstStrBox);
			this->Controls->Add(this->LoggerTxtBox);
			this->Controls->Add(this->RunButton);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

	private: System::Void RunButton_Click(System::Object^  sender, System::EventArgs^  e) {
			WSADATA wsaData;
			struct sockaddr_in server;
			SOCKET sock;
			char buf[1024];

			// winsock2の初期化
			WSAStartup(MAKEWORD(2,0), &wsaData);

			// ソケットの作成
			sock = socket(AF_INET, SOCK_STREAM, 0);

			// 接続先指定用構造体の準備
			server.sin_family = AF_INET;
			server.sin_port = htons(12345);
			//server.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

			char* deststr = (char*)(void*)Marshal::StringToHGlobalAnsi(dstStrBox->Text);
			server.sin_addr.S_un.S_addr = inet_addr(deststr);
			if (server.sin_addr.S_un.S_addr == 0xffffffff) {
				struct hostent *host;

				host = gethostbyname(deststr);
				if (host == NULL) {
					RegisterLogger("Host is NULL!");
				}
				server.sin_addr.S_un.S_addr =
					*(unsigned int *)host->h_addr_list[0];
			}

			// サーバに接続
			connect(sock, (struct sockaddr *)&server, sizeof(server));

			// サーバからデータを受信
			memset(buf, 0, sizeof(buf));
			int n = recv(sock, buf, sizeof(buf), 0);

			//printf("%d, %s\n", n, buf);
			System::String^ str = gcnew String(buf);
			RegisterLogger(str);

			// winsock2の終了処理
			WSACleanup();
		}
	};
}


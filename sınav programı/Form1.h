#include "program.h"
int dersler[20][25];
#pragma once

namespace sýnavprogramý {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(	)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		void ilk_deger(int ders_kom[][25])
{
     int i,j;
     for(i=0;i<25;i++){
                       for(j=0;j<25;j++)ders_kom[i][j]=-1;
                       }     
}


int varmi(int ders_kom[][25],int gelen_sira,int gelen_ders)
{
    int i;
    
    for(i=0;i<25;i++){
                      if(ders_kom[gelen_sira][i]==gelen_ders)return 0;
                      }
    return 1;
    
}

void komsuluk_sayisi_sirala(int gelen_dizi[][2])
{
    int i,j,temp;
    for(i=0;i<25;i++){
                      for(j=i+1;j<25;j++){
                                          if(gelen_dizi[i][1]<gelen_dizi[j][1])
                                          {
                                          temp=gelen_dizi[i][1];
                                          gelen_dizi[i][1]=gelen_dizi[j][1];
                                          gelen_dizi[j][1]=temp;
                                          temp=gelen_dizi[i][0];
                                          gelen_dizi[i][0]=gelen_dizi[j][0];
                                          gelen_dizi[j][0]=temp;
                                          }
                                          }
                      }
}


int komsu_degilse(int d_kom[][25],int ilk_ders,int ikinci_ders)
{
    int i;
    for(i=0;i<25;i++)
    {
    if(d_kom[ilk_ders][i]==ikinci_ders) return 0;
    }
    return 1;
}

int komsusu_farkli_renk_mi(int d_kom[][25],int r_say[][2],int ilk_ders,int gelen_renk)
{
    int i,j;
    for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
        {
             if(r_say[j][0]==d_kom[ilk_ders][i])
             {
                  if(r_say[j][1]==gelen_renk) return 0;
             }
        }
    }
    return 1;
}

		
		void ana_program() {
	
	int ders_komsuluk[25][25];
    int komsuluk_sayisi[25][2];
    int renk_sayisi[25][2];
    int k;
    int sayici;
    int a,b,c,d,m,n;
    int p,r,renk;
    
    ilk_deger(ders_komsuluk);
    
    // derslerin komþuluðunu bul
    
    for(a=0;a<25;a++){
                      k=-1;
                      for(b=0;b<20;b++){
                                        for(c=0;c<25;c++){
                                                          if(dersler[b][c]==a)
                                                          {
                                                          for(d=0;d<25;d++){
                                                                            if(dersler[b][d]!=a)
                                                                            if(varmi(ders_komsuluk,a,dersler[b][d]))
                                                                            {
                                                                            ++k;
                                                                            ders_komsuluk[a][k]=dersler[b][d];
                                                                            }
                                                                           }
                                                          }
                                                          }
                                        }
                      }    
    
  // komþuluk sayisi hesaplama
  
    sayici=0;
    for(m=0;m<25;m++){
                      for(n=0;n<25;n++){
                                        if(ders_komsuluk[m][n]!=-1)
                                        ++sayici;
                                        }
                      komsuluk_sayisi[m][1]=sayici;
                      komsuluk_sayisi[m][0]=m;
                      sayici=0;
                      }
    komsuluk_sayisi_sirala(komsuluk_sayisi);              //büyükten küçüðe sýrala
    
    //renklendirme
    for(m=0;m<25;m++)for(n=0;n<2;n++){ renk_sayisi[m][0]=komsuluk_sayisi[m][0];  renk_sayisi[m][1]=0;}
    
    renk=1;
    for(p=0;p<25;++p)
    {
        if(renk_sayisi[p][1]==0  &&  komsuluk_sayisi[p][1]!=0)
        {
             renk_sayisi[p][1]=renk;
             
             for(r=p+1;r<25;++r)
             {
                  if(komsu_degilse(ders_komsuluk,renk_sayisi[p][0],renk_sayisi[r][0])  && 
                     komsusu_farkli_renk_mi(ders_komsuluk,renk_sayisi,renk_sayisi[r][0],renk)  && 
                     renk_sayisi[r][1]==0  &&  komsuluk_sayisi[r][1]!=0 )
                  {
                      renk_sayisi[r][1]=renk;
                  }
             }
             
             ++renk;
        }
    }


}
		
		void yazdir(int dersler[][25]) {
		     int sayi;
			 String^ mesaj=""; String^ mmesaj=""; String^ mmmesaj="";
			 sayi=dersler[0][0]; mesaj+=sayi; sayi=dersler[1][0];  mmesaj+=sayi; sayi=dersler[3][0];  mmmesaj+=sayi;
			 label29->Text=mesaj; label29->Visible=true;
		     label32->Text=mmesaj; label32->Visible=true;
		     label33->Text=mmmesaj; label33->Visible=true;
		}
		
		void sifirla(int dersler[][25], int kullanici) {
		int q,z;
		for(q=kullanici;q<20;q++) {
			for(z=0;z<25;z++) {
			dersler[q][z]=-1;
			                  }
		                  }             }

		
		int ders_ata(int dersler[][25]) {
		    int y=0;
			static int x=0;
			if(checkBox5->CheckState == CheckState::Checked){dersler[x][y]=0; ++y;} if(checkBox6->CheckState == CheckState::Checked){dersler[x][y]=1; ++y;}if(checkBox7->CheckState == CheckState::Checked){dersler[x][y]=2; ++y;}if(checkBox8->CheckState == CheckState::Checked){dersler[x][y]=3; ++y;}if(checkBox9->CheckState == CheckState::Checked){dersler[x][y]=4; ++y;}if(checkBox10->CheckState == CheckState::Checked){dersler[x][y]=5; ++y;}if(checkBox11->CheckState == CheckState::Checked){dersler[x][y]=6; ++y;}if(checkBox12->CheckState == CheckState::Checked){dersler[x][y]=7; ++y;}if(checkBox13->CheckState == CheckState::Checked){dersler[x][y]=8; ++y;}if(checkBox14->CheckState == CheckState::Checked){dersler[x][y]=9; ++y;}if(checkBox15->CheckState == CheckState::Checked){dersler[x][y]=10; ++y;}if(checkBox16->CheckState == CheckState::Checked){dersler[x][y]=11; ++y;}if(checkBox17->CheckState == CheckState::Checked){dersler[x][y]=12; ++y;}if(checkBox18->CheckState == CheckState::Checked){dersler[x][y]=13; ++y;}if(checkBox19->CheckState == CheckState::Checked){dersler[x][y]=14; ++y;}if(checkBox20->CheckState == CheckState::Checked){dersler[x][y]=15; ++y;}if(checkBox21->CheckState == CheckState::Checked){dersler[x][y]=16; ++y;}if(checkBox22->CheckState == CheckState::Checked){dersler[x][y]=17; ++y;}if(checkBox23->CheckState == CheckState::Checked){dersler[x][y]=18; ++y;}if(checkBox24->CheckState == CheckState::Checked){dersler[x][y]=19; ++y;}if(checkBox25->CheckState == CheckState::Checked){dersler[x][y]=20; ++y;}if(checkBox26->CheckState == CheckState::Checked){dersler[x][y]=21; ++y;}if(checkBox27->CheckState == CheckState::Checked){dersler[x][y]=22; ++y;}if(checkBox28->CheckState == CheckState::Checked){dersler[x][y]=23; ++y;}if(checkBox29->CheckState == CheckState::Checked){dersler[x][y]=24; ++y;}
		    ++x; return x;
		
		}
		
		void kontrol() { 
			int a=0;
			static int kullanici=0;
			
			if(checkBox1->CheckState == CheckState::Checked)  { //1.sýnýfsa basla
				if(checkBox13->CheckState == CheckState::Checked){++a;}if(checkBox14->CheckState == CheckState::Checked){++a;}if(checkBox15->CheckState == CheckState::Checked){++a;}if(checkBox16->CheckState == CheckState::Checked){++a;}if(checkBox17->CheckState == CheckState::Checked){++a;}if(checkBox18->CheckState == CheckState::Checked){++a;}
		                                                      } //1.sýnýfsa bitir
			if(checkBox2->CheckState == CheckState::Checked)  { //2.sýnýfsa basla
				if(checkBox19->CheckState == CheckState::Checked){++a;}if(checkBox20->CheckState == CheckState::Checked){++a;}if(checkBox21->CheckState == CheckState::Checked){++a;}if(checkBox22->CheckState == CheckState::Checked){++a;}if(checkBox23->CheckState == CheckState::Checked){++a;}
															  } //2.sýnýfsa bitir
			if(checkBox3->CheckState == CheckState::Checked)  { //3.sýnýfsa basla
				if(checkBox24->CheckState == CheckState::Checked){++a;}if(checkBox25->CheckState == CheckState::Checked){++a;}if(checkBox26->CheckState == CheckState::Checked){++a;}if(checkBox27->CheckState == CheckState::Checked){++a;}if(checkBox28->CheckState == CheckState::Checked){++a;}if(checkBox29->CheckState == CheckState::Checked){++a;}
															  } //3.sýnýfsa bitir
            if(a>3){ //3ten fazla ders seçilmiþse basla
				label31->Visible=true;button5->Visible=true; //Hata mesajý
				   }//3ten fazla ders seçilmiþse bitir
			
			else{//3ten fazla ders seçilmemiþse basla
			    
				sifirla(dersler, kullanici);
				kullanici=ders_ata(dersler);
				yazdir(dersler);
				
				if (kullanici==2) { //kullanýcý tamamlandýysa 
				int i;
				ana_program(); 
				String^ s="";
			 for(int i=0; i<Application::OpenForms->Count;++i)
			 {
					s += Application::OpenForms[i]->ToString()+"\n";
			 }
			 
			 if(s->Contains(Application::ProductName+".program"))
			 {;}
			 else
			 {
			 program^ dýger = gcnew program();
			 dýger->Show();
			 }
				} 
				
				else basa_don(dersler); //kullanýcý tamamlanmadýysa
			   
			}//3ten fazla ders seçilmemiþse bitir
			
}
		void basa_don(int dersler[][25]) {
             checkBox5->Visible=false;checkBox6->Visible=false;checkBox7->Visible=false;checkBox8->Visible=false;checkBox9->Visible=false;checkBox10->Visible=false;checkBox11->Visible=false;checkBox12->Visible=false;checkBox13->Visible=false;checkBox14->Visible=false;checkBox15->Visible=false;checkBox16->Visible=false;checkBox17->Visible=false; checkBox18->Visible=false;checkBox19->Visible=false;checkBox20->Visible=false;checkBox21->Visible=false;checkBox22->Visible=false;checkBox23->Visible=false;checkBox24->Visible=false;checkBox25->Visible=false;checkBox26->Visible=false;checkBox27->Visible=false;checkBox28->Visible=false;checkBox29->Visible=false;//secimlik dersleri kaldýrdýk...	 
			 checkBox5->Checked=false;checkBox6->Checked=false;checkBox7->Checked=false;checkBox8->Checked=false;checkBox9->Checked=false;checkBox10->Checked=false;checkBox11->Checked=false;checkBox12->Checked=false;checkBox13->Checked=false;checkBox14->Checked=false;checkBox15->Checked=false;checkBox16->Checked=false;checkBox17->Checked=false;checkBox18->Checked=false;checkBox19->Checked=false;checkBox20->Checked=false;checkBox21->Checked=false;checkBox22->Checked=false;checkBox23->Checked=false;checkBox24->Checked=false;checkBox25->Checked=false;checkBox26->Checked=false;checkBox27->Checked=false;checkBox28->Checked=false;checkBox29->Checked=false;//secilebilecek dersleri iþaretsiz yapýyoruz...
			 checkBox1->Checked=false;checkBox2->Checked=false;checkBox3->Checked=false;checkBox4->Checked=false; // sýnýf secim c.boxlarýný  daha onceki seçimden baðýmsýz hale getirdik.
			 checkBox1->Enabled=true;checkBox2->Enabled=true;checkBox3->Enabled=true;checkBox4->Enabled=true; // sýnýf secim c.boxlarýný secilebilir hale getirdik.
			 label30->Visible=false;button4->Visible=false;label1->Visible=true;label16->Visible=true;textBox1->Visible=true;checkBox1->Visible=true;checkBox2->Visible=true;checkBox3->Visible=true;checkBox4->Visible=true;button1->Visible=true;textBox1->Text="";// sýnýf secim c.boxlarýný görünebilir hale getirdik.
}
		void zorunlu_ders_kaybet(void) {
		label2->Visible=false;label3->Visible=false;label4->Visible=false;label5->Visible=false;label6->Visible=false;label7->Visible=false;label8->Visible=false;label9->Visible=false;label11->Visible=false;label12->Visible=false;label13->Visible=false;label14->Visible=false;label15->Visible=false;label17->Visible=false;
		label18->Visible=false;label19->Visible=false;label20->Visible=false;label21->Visible=false;label22->Visible=false;label23->Visible=false;label24->Visible=false;label25->Visible=false;label26->Visible=false;label27->Visible=false;label28->Visible=false;
}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected: 
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::CheckBox^  checkBox11;
	private: System::Windows::Forms::CheckBox^  checkBox12;
	private: System::Windows::Forms::CheckBox^  checkBox13;
	private: System::Windows::Forms::CheckBox^  checkBox14;
	private: System::Windows::Forms::CheckBox^  checkBox15;
	private: System::Windows::Forms::CheckBox^  checkBox16;
	private: System::Windows::Forms::CheckBox^  checkBox17;
	private: System::Windows::Forms::CheckBox^  checkBox18;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label28;

private: System::Windows::Forms::CheckBox^  checkBox19;
private: System::Windows::Forms::CheckBox^  checkBox20;
private: System::Windows::Forms::CheckBox^  checkBox21;
private: System::Windows::Forms::CheckBox^  checkBox22;
private: System::Windows::Forms::CheckBox^  checkBox23;
private: System::Windows::Forms::CheckBox^  checkBox24;
private: System::Windows::Forms::CheckBox^  checkBox25;
private: System::Windows::Forms::CheckBox^  checkBox26;
private: System::Windows::Forms::CheckBox^  checkBox27;
private: System::Windows::Forms::CheckBox^  checkBox28;
private: System::Windows::Forms::CheckBox^  checkBox29;

private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label34;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		
		void InitializeComponent(void)
		{
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox25 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox27 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox28 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox29 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(127, 174);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(53, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"1.sýnýf";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(192, 174);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(53, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"2.sýnýf";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(127, 223);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(53, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"3.sýnýf";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 201);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"sýnýf seçimi yapýnýz:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::SaddleBrown;
			this->label10->Location = System::Drawing::Point(87, 75);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(79, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Zorunlu Dersler";
			this->label10->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(561, 430);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 22;
			this->button1->Text = L"ileri";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(192, 223);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(53, 17);
			this->checkBox4->TabIndex = 21;
			this->checkBox4->Text = L"4.sýnýf";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(8, 59);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(76, 13);
			this->label16->TabIndex = 26;
			this->label16->Text = L"öðrencinin adý:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(127, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 27;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(340, 244);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"ders ekle";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(61, 112);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(180, 17);
			this->checkBox5->TabIndex = 31;
			this->checkBox5->Text = L"Atatürk Ýlkeleri ve Ýnkýlap Tarihi II";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->Visible = false;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(61, 142);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(74, 17);
			this->checkBox6->TabIndex = 32;
			this->checkBox6->Text = L"Türk Dili 2";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->Visible = false;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(61, 174);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(73, 17);
			this->checkBox7->TabIndex = 33;
			this->checkBox7->Text = L"Ýngilizce II";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->Visible = false;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(61, 201);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(56, 17);
			this->checkBox8->TabIndex = 34;
			this->checkBox8->Text = L"Fizik II";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->Visible = false;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(61, 227);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(84, 17);
			this->checkBox9->TabIndex = 35;
			this->checkBox9->Text = L"Matematik II";
			this->checkBox9->UseVisualStyleBackColor = true;
			this->checkBox9->Visible = false;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(61, 259);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(147, 17);
			this->checkBox10->TabIndex = 36;
			this->checkBox10->Text = L"Bilgisayar Laboratuvarý - II";
			this->checkBox10->UseVisualStyleBackColor = true;
			this->checkBox10->Visible = false;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox10_CheckedChanged);
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(61, 290);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(96, 17);
			this->checkBox11->TabIndex = 37;
			this->checkBox11->Text = L"Programlama II";
			this->checkBox11->UseVisualStyleBackColor = true;
			this->checkBox11->Visible = false;
			this->checkBox11->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox11_CheckedChanged);
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Location = System::Drawing::Point(61, 318);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(216, 17);
			this->checkBox12->TabIndex = 38;
			this->checkBox12->Text = L"Elektrik Devre Temelleri ve Uygulamalarý";
			this->checkBox12->UseVisualStyleBackColor = true;
			this->checkBox12->Visible = false;
			// 
			// checkBox13
			// 
			this->checkBox13->AutoSize = true;
			this->checkBox13->Location = System::Drawing::Point(61, 349);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(176, 17);
			this->checkBox13->TabIndex = 39;
			this->checkBox13->Text = L"Olasýlýk ve Raslantý Deðiþkenleri";
			this->checkBox13->UseVisualStyleBackColor = true;
			this->checkBox13->Visible = false;
			this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox13_CheckedChanged);
			// 
			// checkBox14
			// 
			this->checkBox14->AutoSize = true;
			this->checkBox14->Location = System::Drawing::Point(61, 382);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(151, 17);
			this->checkBox14->TabIndex = 40;
			this->checkBox14->Text = L"Elektronik ve Uygulamalarý";
			this->checkBox14->UseVisualStyleBackColor = true;
			this->checkBox14->Visible = false;
			// 
			// checkBox15
			// 
			this->checkBox15->AutoSize = true;
			this->checkBox15->Location = System::Drawing::Point(61, 405);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(198, 17);
			this->checkBox15->TabIndex = 41;
			this->checkBox15->Text = L"Bilgisayar Organizasyonu ve Mimarisi";
			this->checkBox15->UseVisualStyleBackColor = true;
			this->checkBox15->Visible = false;
			// 
			// checkBox16
			// 
			this->checkBox16->AutoSize = true;
			this->checkBox16->Location = System::Drawing::Point(61, 430);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(116, 17);
			this->checkBox16->TabIndex = 42;
			this->checkBox16->Text = L"Veritabaný Yönetimi";
			this->checkBox16->UseVisualStyleBackColor = true;
			this->checkBox16->Visible = false;
			// 
			// checkBox17
			// 
			this->checkBox17->AutoSize = true;
			this->checkBox17->Location = System::Drawing::Point(61, 458);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(166, 17);
			this->checkBox17->TabIndex = 43;
			this->checkBox17->Text = L"Programlama Laboratuvarý – II";
			this->checkBox17->UseVisualStyleBackColor = true;
			this->checkBox17->Visible = false;
			// 
			// checkBox18
			// 
			this->checkBox18->AutoSize = true;
			this->checkBox18->Location = System::Drawing::Point(61, 488);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(121, 17);
			this->checkBox18->TabIndex = 44;
			this->checkBox18->Text = L"Sistem Programlama";
			this->checkBox18->UseVisualStyleBackColor = true;
			this->checkBox18->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 13);
			this->label2->TabIndex = 45;
			this->label2->Text = L"Atatürk Ýlkeleri ve Ýnkýlap Tarihi II";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(87, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 46;
			this->label3->Text = L"Türk Dili 2";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(87, 174);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 13);
			this->label4->TabIndex = 47;
			this->label4->Text = L"Ýngilizce II";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(87, 201);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 48;
			this->label5->Text = L"Fizik II";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(87, 231);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 13);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Matematik II";
			this->label6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(87, 260);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(128, 13);
			this->label7->TabIndex = 50;
			this->label7->Text = L"Bilgisayar Laboratuvarý - II";
			this->label7->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(87, 294);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(77, 13);
			this->label8->TabIndex = 51;
			this->label8->Text = L"Programlama II";
			this->label8->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(87, 319);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(197, 13);
			this->label9->TabIndex = 52;
			this->label9->Text = L"Elektrik Devre Temelleri ve Uygulamalarý";
			this->label9->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(90, 111);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(157, 13);
			this->label11->TabIndex = 53;
			this->label11->Text = L"Olasýlýk ve Raslantý Deðiþkenleri";
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(90, 141);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(132, 13);
			this->label12->TabIndex = 54;
			this->label12->Text = L"Elektronik ve Uygulamalarý";
			this->label12->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(90, 174);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(179, 13);
			this->label13->TabIndex = 55;
			this->label13->Text = L"Bilgisayar Organizasyonu ve Mimarisi";
			this->label13->Visible = false;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(90, 201);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(97, 13);
			this->label14->TabIndex = 56;
			this->label14->Text = L"Veritabaný Yönetimi";
			this->label14->Visible = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(90, 232);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(147, 13);
			this->label15->TabIndex = 57;
			this->label15->Text = L"Programlama Laboratuvarý – II";
			this->label15->Visible = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(90, 263);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(102, 13);
			this->label17->TabIndex = 58;
			this->label17->Text = L"Sistem Programlama";
			this->label17->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(90, 110);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(81, 13);
			this->label18->TabIndex = 59;
			this->label18->Text = L"Otomata Teorisi";
			this->label18->Visible = false;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(90, 142);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(97, 13);
			this->label19->TabIndex = 60;
			this->label19->Text = L"Sayýsal Veri Ýletiþimi";
			this->label19->Visible = false;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(90, 174);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(116, 13);
			this->label20->TabIndex = 61;
			this->label20->Text = L"Yazýlým Laboratuvarý - II";
			this->label20->Visible = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(90, 201);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(100, 13);
			this->label21->TabIndex = 62;
			this->label21->Text = L"Yazýlým Mühendisliði";
			this->label21->Visible = false;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(93, 231);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(84, 13);
			this->label22->TabIndex = 63;
			this->label22->Text = L"Ýleri Veritabanlarý";
			this->label22->Visible = false;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(90, 111);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(100, 13);
			this->label23->TabIndex = 64;
			this->label23->Text = L"Nöron Aðlarýna Giriþ";
			this->label23->Visible = false;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(90, 143);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(137, 13);
			this->label24->TabIndex = 65;
			this->label24->Text = L"Sayýsal Entegre Tasarým Dili";
			this->label24->Visible = false;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(90, 174);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(147, 13);
			this->label25->TabIndex = 66;
			this->label25->Text = L"Programlama Dilleri Prensipleri";
			this->label25->Visible = false;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(90, 201);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(180, 13);
			this->label26->TabIndex = 67;
			this->label26->Text = L"Bilgisayar Destekli Tasarým ve Üretim";
			this->label26->Visible = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(90, 231);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(99, 13);
			this->label27->TabIndex = 68;
			this->label27->Text = L"Sistem Mühendisliði";
			this->label27->Visible = false;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(90, 259);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(65, 13);
			this->label28->TabIndex = 69;
			this->label28->Text = L"Yapay Zeka";
			this->label28->Visible = false;
			// 
			// checkBox19
			// 
			this->checkBox19->AutoSize = true;
			this->checkBox19->Location = System::Drawing::Point(315, 112);
			this->checkBox19->Name = L"checkBox19";
			this->checkBox19->Size = System::Drawing::Size(100, 17);
			this->checkBox19->TabIndex = 71;
			this->checkBox19->Text = L"Otomata Teorisi";
			this->checkBox19->UseVisualStyleBackColor = true;
			this->checkBox19->Visible = false;
			// 
			// checkBox20
			// 
			this->checkBox20->AutoSize = true;
			this->checkBox20->Location = System::Drawing::Point(316, 142);
			this->checkBox20->Name = L"checkBox20";
			this->checkBox20->Size = System::Drawing::Size(116, 17);
			this->checkBox20->TabIndex = 72;
			this->checkBox20->Text = L"Sayýsal Veri Ýletiþimi";
			this->checkBox20->UseVisualStyleBackColor = true;
			this->checkBox20->Visible = false;
			// 
			// checkBox21
			// 
			this->checkBox21->AutoSize = true;
			this->checkBox21->Location = System::Drawing::Point(316, 170);
			this->checkBox21->Name = L"checkBox21";
			this->checkBox21->Size = System::Drawing::Size(135, 17);
			this->checkBox21->TabIndex = 73;
			this->checkBox21->Text = L"Yazýlým Laboratuvarý - II";
			this->checkBox21->UseVisualStyleBackColor = true;
			this->checkBox21->Visible = false;
			// 
			// checkBox22
			// 
			this->checkBox22->AutoSize = true;
			this->checkBox22->Location = System::Drawing::Point(316, 197);
			this->checkBox22->Name = L"checkBox22";
			this->checkBox22->Size = System::Drawing::Size(119, 17);
			this->checkBox22->TabIndex = 74;
			this->checkBox22->Text = L"Yazýlým Mühendisliði";
			this->checkBox22->UseVisualStyleBackColor = true;
			this->checkBox22->Visible = false;
			// 
			// checkBox23
			// 
			this->checkBox23->AutoSize = true;
			this->checkBox23->Location = System::Drawing::Point(316, 231);
			this->checkBox23->Name = L"checkBox23";
			this->checkBox23->Size = System::Drawing::Size(103, 17);
			this->checkBox23->TabIndex = 75;
			this->checkBox23->Text = L"Ýleri Veritabanlarý";
			this->checkBox23->UseVisualStyleBackColor = true;
			this->checkBox23->Visible = false;
			// 
			// checkBox24
			// 
			this->checkBox24->AutoSize = true;
			this->checkBox24->Location = System::Drawing::Point(316, 263);
			this->checkBox24->Name = L"checkBox24";
			this->checkBox24->Size = System::Drawing::Size(119, 17);
			this->checkBox24->TabIndex = 76;
			this->checkBox24->Text = L"Nöron Aðlarýna Giriþ";
			this->checkBox24->UseVisualStyleBackColor = true;
			this->checkBox24->Visible = false;
			// 
			// checkBox25
			// 
			this->checkBox25->AutoSize = true;
			this->checkBox25->Location = System::Drawing::Point(316, 289);
			this->checkBox25->Name = L"checkBox25";
			this->checkBox25->Size = System::Drawing::Size(156, 17);
			this->checkBox25->TabIndex = 77;
			this->checkBox25->Text = L"Sayýsal Entegre Tasarým Dili";
			this->checkBox25->UseVisualStyleBackColor = true;
			this->checkBox25->Visible = false;
			// 
			// checkBox26
			// 
			this->checkBox26->AutoSize = true;
			this->checkBox26->Location = System::Drawing::Point(316, 315);
			this->checkBox26->Name = L"checkBox26";
			this->checkBox26->Size = System::Drawing::Size(166, 17);
			this->checkBox26->TabIndex = 78;
			this->checkBox26->Text = L"Programlama Dilleri Prensipleri";
			this->checkBox26->UseVisualStyleBackColor = true;
			this->checkBox26->Visible = false;
			// 
			// checkBox27
			// 
			this->checkBox27->AutoSize = true;
			this->checkBox27->Location = System::Drawing::Point(316, 342);
			this->checkBox27->Name = L"checkBox27";
			this->checkBox27->Size = System::Drawing::Size(199, 17);
			this->checkBox27->TabIndex = 79;
			this->checkBox27->Text = L"Bilgisayar Destekli Tasarým ve Üretim";
			this->checkBox27->UseVisualStyleBackColor = true;
			this->checkBox27->Visible = false;
			// 
			// checkBox28
			// 
			this->checkBox28->AutoSize = true;
			this->checkBox28->Location = System::Drawing::Point(316, 365);
			this->checkBox28->Name = L"checkBox28";
			this->checkBox28->Size = System::Drawing::Size(118, 17);
			this->checkBox28->TabIndex = 80;
			this->checkBox28->Text = L"Sistem Mühendisliði";
			this->checkBox28->UseVisualStyleBackColor = true;
			this->checkBox28->Visible = false;
			// 
			// checkBox29
			// 
			this->checkBox29->AutoSize = true;
			this->checkBox29->Location = System::Drawing::Point(316, 388);
			this->checkBox29->Name = L"checkBox29";
			this->checkBox29->Size = System::Drawing::Size(84, 17);
			this->checkBox29->TabIndex = 81;
			this->checkBox29->Text = L"Yapay Zeka";
			this->checkBox29->UseVisualStyleBackColor = true;
			this->checkBox29->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(316, 470);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 83;
			this->button4->Text = L"tamam";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->ForeColor = System::Drawing::Color::Maroon;
			this->label30->Location = System::Drawing::Point(189, 75);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(107, 13);
			this->label30->TabIndex = 84;
			this->label30->Text = L"SEÇMELÝ DERSLER";
			this->label30->Visible = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(235, 263);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 85;
			this->button5->Text = L"tamam";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(255, 244);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(36, 13);
			this->label31->TabIndex = 86;
			this->label31->Text = L"HATA";
			this->label31->Visible = false;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(561, 111);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(41, 13);
			this->label29->TabIndex = 87;
			this->label29->Text = L"label29";
			this->label29->Visible = false;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(561, 141);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(41, 13);
			this->label32->TabIndex = 88;
			this->label32->Text = L"label32";
			this->label32->Visible = false;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(561, 173);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(41, 13);
			this->label33->TabIndex = 89;
			this->label33->Text = L"label33";
			this->label33->Visible = false;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(564, 201);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(41, 13);
			this->label34->TabIndex = 90;
			this->label34->Text = L"label34";
			this->label34->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(702, 543);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->checkBox29);
			this->Controls->Add(this->checkBox28);
			this->Controls->Add(this->checkBox27);
			this->Controls->Add(this->checkBox26);
			this->Controls->Add(this->checkBox25);
			this->Controls->Add(this->checkBox24);
			this->Controls->Add(this->checkBox23);
			this->Controls->Add(this->checkBox22);
			this->Controls->Add(this->checkBox21);
			this->Controls->Add(this->checkBox20);
			this->Controls->Add(this->checkBox19);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox18);
			this->Controls->Add(this->checkBox17);
			this->Controls->Add(this->checkBox16);
			this->Controls->Add(this->checkBox15);
			this->Controls->Add(this->checkBox14);
			this->Controls->Add(this->checkBox13);
			this->Controls->Add(this->checkBox12);
			this->Controls->Add(this->checkBox11);
			this->Controls->Add(this->checkBox10);
			this->Controls->Add(this->checkBox9);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 checkBox2->Enabled=false;checkBox3->Enabled=false;checkBox4->Enabled=false;
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label18_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {		  
			 String^ mesaj=textBox1->Text;

			 if(mesaj=="") { //öðrenci adý girilmediyse veya kelimeden baska bir terim grildiyse
				 button1->Enabled=false;
				 return;
			 }
			 else button1->Enabled=true;

			 //if(checkBox1->CheckState == CheckState::Checked)
			 //mesaj+="ingilizce";
			 
			 //label2->Text=mesaj;
			 
			 //label2->Visible=true;

		

			checkBox1->Visible=false;checkBox2->Visible=false;//sýnýf secim 
		    checkBox3->Visible=false;checkBox4->Visible=false;//check box larý 
			label1->Visible=false;label16->Visible=false;textBox1->Visible=false; //sýnýf secimi yazýsý,ogrnci adý,text box
			button1->Visible=false;label10->Visible=true;//ileri, zorunlu dersler 
			button2->Visible=true;//ders ekle, bitir
			
			if(checkBox1->CheckState == CheckState::Checked) {
			label2->Visible=true;label3->Visible=true;label4->Visible=true;label5->Visible=true;//1.sýnýfýn zorunlu dersleri
			label6->Visible=true;label7->Visible=true;label8->Visible=true;label9->Visible=true;
														     } 

			if(checkBox2->CheckState == CheckState::Checked) {
			label11->Visible=true;label12->Visible=true;label13->Visible=true;
			label14->Visible=true;label15->Visible=true;label17->Visible=true;//2.sýnýfýn zorunlu dersleri
			                                                 } 

			if(checkBox3->CheckState == CheckState::Checked) {
			label18->Visible=true;label19->Visible=true;label20->Visible=true;
			label21->Visible=true;label22->Visible=true;//3.sýnýfýn zorunlu dersleri
															 } 

			if(checkBox4->CheckState == CheckState::Checked) {
			label23->Visible=true;label24->Visible=true;label25->Visible=true;label26->Visible=true;
			label27->Visible=true;label28->Visible=true;//4.sýnýfýn zorunlu dersleri
															 } 

		 }
private: System::Void checkBox11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkBox10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void checkBox13_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 label10->Visible=false;button1->Visible=false;button2->Visible=false;button4->Visible=true;label30->Visible=true;//zorunlu dersler yazýsý, ileri, bitir, ders ekle butonlarýný kaybet, tamam butonu,seçmeli dersler yazýsýný aktifleþtir...
			 checkBox5->Visible=true;checkBox6->Visible=true;checkBox7->Visible=true;checkBox8->Visible=true;checkBox9->Visible=true;checkBox10->Visible=true;checkBox11->Visible=true;checkBox12->Visible=true;checkBox13->Visible=true;checkBox14->Visible=true;checkBox15->Visible=true;checkBox16->Visible=true;checkBox17->Visible=true;checkBox18->Visible=true;checkBox19->Visible=true;checkBox20->Visible=true;checkBox21->Visible=true;checkBox22->Visible=true;checkBox23->Visible=true;checkBox24->Visible=true;checkBox25->Visible=true;checkBox26->Visible=true;checkBox27->Visible=true;checkBox28->Visible=true;checkBox29->Visible=true;//secmeli dersleri görünür yaptýk...
			 checkBox5->Enabled=true;checkBox6->Enabled=true;checkBox7->Enabled=true;checkBox8->Enabled=true;checkBox9->Enabled=true;checkBox10->Enabled=true;checkBox11->Enabled=true;checkBox12->Enabled=true;checkBox13->Enabled=true;checkBox14->Enabled=true;checkBox15->Enabled=true;checkBox16->Enabled=true;checkBox17->Enabled=true;checkBox18->Enabled=true;checkBox19->Enabled=true;checkBox20->Enabled=true;checkBox21->Enabled=true;checkBox22->Enabled=true;checkBox23->Enabled=true;checkBox24->Enabled=true;checkBox25->Enabled=true;checkBox26->Enabled=true;checkBox27->Enabled=true;checkBox28->Enabled=true;checkBox29->Enabled=true;//secmeli dersleri secilebilir hale getirdik...
			 
			 if(checkBox1->CheckState == CheckState::Checked) { label2->Visible=false;label3->Visible=false;label4->Visible=false;label5->Visible=false;label6->Visible=false;label7->Visible=false;label8->Visible=false;label9->Visible=false; //1.sýnýfsa 1.sýnýfýn zorunlu derslerini kaybet.
			 checkBox5->Checked=true;checkBox6->Checked=true;checkBox7->Checked=true;checkBox8->Checked=true;checkBox9->Checked=true;checkBox10->Checked=true;checkBox11->Checked=true;checkBox12->Checked=true;
			 checkBox5->Enabled=false;checkBox6->Enabled=false;checkBox7->Enabled=false;checkBox8->Enabled=false;checkBox9->Enabled=false;checkBox10->Enabled=false;checkBox11->Enabled=false;checkBox12->Enabled=false;checkBox19->Enabled=false;checkBox20->Enabled=false;checkBox21->Enabled=false;checkBox22->Enabled=false;checkBox23->Enabled=false;checkBox24->Enabled=false;checkBox25->Enabled=false;checkBox26->Enabled=false;checkBox27->Enabled=false;checkBox28->Enabled=false;checkBox29->Enabled=false; } //1.sýnýfsa 1. , 3. , 4. sýnýfýn zorunlu derslerini ve  seçmesini engelle.
			 if(checkBox2->CheckState == CheckState::Checked) { label11->Visible=false;label12->Visible=false;label13->Visible=false;label14->Visible=false;label15->Visible=false;label17->Visible=false;//2.sýnýfsa 2. sýnýfýn zorunlu derslerini kaybet.
			 checkBox13->Checked=true;checkBox14->Checked=true;checkBox15->Checked=true;checkBox16->Checked=true;checkBox17->Checked=true;checkBox18->Checked=true;
			 checkBox13->Enabled=false;checkBox14->Enabled=false;checkBox15->Enabled=false;checkBox16->Enabled=false;checkBox17->Enabled=false;checkBox18->Enabled=false;checkBox24->Enabled=false;checkBox25->Enabled=false;checkBox26->Enabled=false;checkBox27->Enabled=false;checkBox28->Enabled=false;checkBox29->Enabled=false; }  //2.sýnýfsa 2., 4. sýnýfýn zorunlu derslerini seçmesini engelle.
			 if(checkBox3->CheckState == CheckState::Checked) { label18->Visible=false;label19->Visible=false;label20->Visible=false;label21->Visible=false;label22->Visible=false;//3.sýnýfsa 3.sýnýfýn zorunlu derslerini kaybet.
			 checkBox19->Checked=true;checkBox20->Checked=true;checkBox21->Checked=true;checkBox22->Checked=true;checkBox23->Checked=true;
			 checkBox19->Enabled=false;checkBox20->Enabled=false;checkBox21->Enabled=false;checkBox22->Enabled=false;checkBox23->Enabled=false; } //3.sýnýfsa 3.sýnýfýn zorunlu derslerini seçmesini engelle.
			 if(checkBox4->CheckState == CheckState::Checked) { label23->Visible=false;label24->Visible=false;label25->Visible=false;label26->Visible=false;label27->Visible=false;label28->Visible=false;//4.sýnýfsa 4.sýnýfýn zorunlu derslerini kaybet.
			 checkBox24->Checked=true;checkBox25->Checked=true;checkBox26->Checked=true;checkBox27->Checked=true;checkBox28->Checked=true;checkBox29->Checked=true;
			 checkBox24->Enabled=false;checkBox25->Enabled=false;checkBox26->Enabled=false;checkBox27->Enabled=false;checkBox28->Enabled=false;checkBox29->Enabled=false; } //4.sýnýfsa 4.sýnýfýn zorunlu derslerini seçmesini engelle.
			 
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 checkBox1->Enabled=false;checkBox3->Enabled=false;checkBox4->Enabled=false;
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		     checkBox1->Enabled=false;checkBox2->Enabled=false;checkBox4->Enabled=false;
		 }
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		     checkBox1->Enabled=false;checkBox2->Enabled=false;checkBox3->Enabled=false;
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 kontrol(); 
			                             
			 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 button5->Visible=false; label31->Visible=false;
		 }
};
}


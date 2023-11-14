#pragma once
#using <Microsoft.VisualBasic.dll>

using namespace System::Collections::Generic;

namespace Zav1 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    /// <summary>
    /// Summary for MyForm
    /// </summary>
    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    protected:
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::ListBox^ listBox1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(629, 85);
            this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3,

                4);

            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(178, 29);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Додати елементи";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this,

                &MyForm::button1_Click);
            //
            // textBox1
            //
            this->textBox1->Location = System::Drawing::Point(216, 88);
            this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3,

                4);

            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(112, 26);
            this->textBox1->TabIndex = 1;
            //
            // listBox1
            //
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 20;
            this->listBox1->Location = System::Drawing::Point(371, 82);
            this->listBox1->Margin = System::Windows::Forms::Padding(3, 4, 3,

                4);

            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(182, 184);
            this->listBox1->TabIndex = 2;
            //
            // button2
            //
            this->button2->Location = System::Drawing::Point(629, 177);
            this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);

            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(178, 29);
            this->button2->TabIndex = 3;
            this->button2->Text = L"Видалити елементи";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            //
            // button3
            //
            this->button3->Location = System::Drawing::Point(397, 324);
            this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);


            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(133, 29);
            this->button3->TabIndex = 4;
            this->button3->Text = L"Обчислити";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(231, 26);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(524, 20);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Заповнити чергу числами. Обчислити кількість однозначних елементів черги.";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(30, 94);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(170, 20);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Введіть розмір черги";
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(982, 639);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->listBox1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
        System::Collections::Generic::Queue<int> myQueue1; // Оголошення черги
        int lastAddedValue;
        bool isQueueInitialized = false; // ініціалізацію черги

#pragma endregion
  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
      if (!isQueueInitialized)
      {
          isQueueInitialized = true;
      }
      // Отримуємо розмір черги з textBox1
      int size = Convert::ToInt32(textBox1->Text);
      if (myQueue1.Count < size)
      {
          String^ valueInput = Microsoft::VisualBasic::Interaction::InputBox("Введіть елемент черги:", "Додавання елементу", "0");
          if (valueInput == "")
          {
              return;
          }
          int inputValue = Convert::ToInt32(valueInput);
          myQueue1.Enqueue(inputValue);
          listBox1->Items->Add(inputValue.ToString());
          lastAddedValue = inputValue;
      }
      else
      {
          listBox1->Items->Add("Досягнуто ліміт чисел");
      }
  }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^
    e) {

    if (isQueueInitialized)
    {
        if (myQueue1.Count > 0)
        {
            myQueue1.Dequeue();
            listBox1->Items->Clear();
            for each (int value in myQueue1)
            {
                listBox1->Items->Add(value.ToString());
            }
        }
        else
        {
            listBox1->Items->Add("Черга порожня");
        }
    }
    else
    {
        listBox1->Items->Add("Черга ще не була ініціалізована");
    }
}
  private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
      int count = 0;
      for each (int value in myQueue1)
      {
          if (value > -10 && value < 10)
          {
              count++;
          }
      }
      MessageBox::Show(count.ToString());
  }
};
}

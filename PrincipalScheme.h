#pragma once
#include "DrawingField.h"
#include "Element.h"
#include "Line.h"
#include "Lamp.h"
#include "Fuse.h"
#include "Ammeter.h"
#include "GalvanicCell.h"
#include "Coil.h"

namespace IDZ_OOP {

	constexpr int CURSOR = 0;
	constexpr int LINE = 1;
	constexpr int LAMP = 2;
	constexpr int FUSE = 3;
	constexpr int AMMETER = 4;
	constexpr int GALVANICCELL = 5;
	constexpr int COIL = 6;
	constexpr int DELETE = 10;


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для VecEditor
	/// </summary>
/// <summary>
	/// Сводка для VecEditor
	/// </summary>
	public ref class PrincipalScheme : public System::Windows::Forms::Form
	{
	public:
		PrincipalScheme(void)
		{
			InitializeComponent();


			maxnetworkBoxHeight = networkBox->Height;
			maxnetworkBoxWidth = networkBox->Width;
			isDown = false;

			Bitmap^ bitmap = gcnew Bitmap(networkBox->Size.Width, networkBox->Size.Height);
			Graphics^ g = Graphics::FromImage(bitmap);
			g->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, networkBox->Width, networkBox->Height);
			networkBox->Image = bitmap;

			draw();

			cursorType = CURSOR;
		}

	protected:
		~PrincipalScheme()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Button^ cursorButton;
	private: System::Windows::Forms::Button^ lineButton;
	private: System::Windows::Forms::Button^ deleteButton;

	private: System::Windows::Forms::PictureBox^ networkBox;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ lampButton;
	private: System::Windows::Forms::Button^ fuseButton;
	private: System::Windows::Forms::Button^ ammeterButton;
	private: System::Windows::Forms::Button^ galvaniccellButton;
	private: System::Windows::Forms::PictureBox^ LampImage;
	private: System::Windows::Forms::PictureBox^ FuseImage;
	private: System::Windows::Forms::PictureBox^ AmmeterImage;
	private: System::Windows::Forms::PictureBox^ GalvanicCellImage;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ coilButton;
	private: System::Windows::Forms::PictureBox^ CoilImage;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	protected:
	private:
		System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->cursorButton = (gcnew System::Windows::Forms::Button());
			this->lineButton = (gcnew System::Windows::Forms::Button());
			this->networkBox = (gcnew System::Windows::Forms::PictureBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lampButton = (gcnew System::Windows::Forms::Button());
			this->fuseButton = (gcnew System::Windows::Forms::Button());
			this->ammeterButton = (gcnew System::Windows::Forms::Button());
			this->galvaniccellButton = (gcnew System::Windows::Forms::Button());
			this->LampImage = (gcnew System::Windows::Forms::PictureBox());
			this->FuseImage = (gcnew System::Windows::Forms::PictureBox());
			this->AmmeterImage = (gcnew System::Windows::Forms::PictureBox());
			this->GalvanicCellImage = (gcnew System::Windows::Forms::PictureBox());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->coilButton = (gcnew System::Windows::Forms::Button());
			this->CoilImage = (gcnew System::Windows::Forms::PictureBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->networkBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LampImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FuseImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AmmeterImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GalvanicCellImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CoilImage))->BeginInit();
			this->SuspendLayout();
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clearButton->Location = System::Drawing::Point(12, 11);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(135, 80);
			this->clearButton->TabIndex = 3;
			this->clearButton->Text = L"Очистить";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::clearButton_Click);
			// 
			// cursorButton
			// 
			this->cursorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cursorButton->Location = System::Drawing::Point(12, 97);
			this->cursorButton->Name = L"cursorButton";
			this->cursorButton->Size = System::Drawing::Size(135, 80);
			this->cursorButton->TabIndex = 4;
			this->cursorButton->Text = L"Курсор";
			this->cursorButton->UseVisualStyleBackColor = true;
			this->cursorButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::cursorButton_Click);
			// 
			// lineButton
			// 
			this->lineButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lineButton->Location = System::Drawing::Point(12, 214);
			this->lineButton->Name = L"lineButton";
			this->lineButton->Size = System::Drawing::Size(135, 80);
			this->lineButton->TabIndex = 5;
			this->lineButton->Text = L"Линия";
			this->lineButton->UseVisualStyleBackColor = true;
			this->lineButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::lineButton_Click);
			// 
			// networkBox
			// 
			this->networkBox->Location = System::Drawing::Point(339, 11);
			this->networkBox->Name = L"networkBox";
			this->networkBox->Size = System::Drawing::Size(729, 456);
			this->networkBox->TabIndex = 0;
			this->networkBox->TabStop = false;
			this->networkBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PrincipalScheme::networkBox_MouseDown);
			this->networkBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PrincipalScheme::networkBox_MouseMove);
			this->networkBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PrincipalScheme::networkBox_MouseUp);
			// 
			// deleteButton
			// 
			this->deleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->deleteButton->Location = System::Drawing::Point(153, 97);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(135, 80);
			this->deleteButton->TabIndex = 9;
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::deleteButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(58, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 31);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Элементы схемы";
			// 
			// lampButton
			// 
			this->lampButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lampButton->Location = System::Drawing::Point(12, 301);
			this->lampButton->Name = L"lampButton";
			this->lampButton->Size = System::Drawing::Size(135, 80);
			this->lampButton->TabIndex = 14;
			this->lampButton->Text = L"Лампа";
			this->lampButton->UseVisualStyleBackColor = true;
			this->lampButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::lampButton_Click);
			// 
			// fuseButton
			// 
			this->fuseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fuseButton->Location = System::Drawing::Point(12, 387);
			this->fuseButton->Name = L"fuseButton";
			this->fuseButton->Size = System::Drawing::Size(135, 80);
			this->fuseButton->TabIndex = 15;
			this->fuseButton->Text = L"Предохранитель";
			this->fuseButton->UseVisualStyleBackColor = true;
			this->fuseButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::fuseButton_Click);
			// 
			// ammeterButton
			// 
			this->ammeterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ammeterButton->Location = System::Drawing::Point(153, 387);
			this->ammeterButton->Name = L"ammeterButton";
			this->ammeterButton->Size = System::Drawing::Size(135, 80);
			this->ammeterButton->TabIndex = 16;
			this->ammeterButton->Text = L"Амперметр";
			this->ammeterButton->UseVisualStyleBackColor = true;
			this->ammeterButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::ammeterButton_Click);
			// 
			// galvaniccellButton
			// 
			this->galvaniccellButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->galvaniccellButton->Location = System::Drawing::Point(153, 301);
			this->galvaniccellButton->Name = L"galvaniccellButton";
			this->galvaniccellButton->Size = System::Drawing::Size(135, 80);
			this->galvaniccellButton->TabIndex = 17;
			this->galvaniccellButton->Text = L"Батарея";
			this->galvaniccellButton->UseVisualStyleBackColor = true;
			this->galvaniccellButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::galvaniccellButton_Click);
			// 
			// LampImage
			// 
			this->LampImage->Location = System::Drawing::Point(25, 473);
			this->LampImage->Name = L"LampImage";
			this->LampImage->Size = System::Drawing::Size(93, 32);
			this->LampImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->LampImage->TabIndex = 18;
			this->LampImage->TabStop = false;
			// 
			// FuseImage
			// 
			this->FuseImage->Location = System::Drawing::Point(11, 469);
			this->FuseImage->Name = L"FuseImage";
			this->FuseImage->Size = System::Drawing::Size(163, 36);
			this->FuseImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->FuseImage->TabIndex = 19;
			this->FuseImage->TabStop = false;
			// 
			// AmmeterImage
			// 
			this->AmmeterImage->Location = System::Drawing::Point(39, 469);
			this->AmmeterImage->Name = L"AmmeterImage";
			this->AmmeterImage->Size = System::Drawing::Size(148, 36);
			this->AmmeterImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->AmmeterImage->TabIndex = 20;
			this->AmmeterImage->TabStop = false;
			// 
			// GalvanicCellImage
			// 
			this->GalvanicCellImage->Location = System::Drawing::Point(39, 469);
			this->GalvanicCellImage->Name = L"GalvanicCellImage";
			this->GalvanicCellImage->Size = System::Drawing::Size(121, 49);
			this->GalvanicCellImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->GalvanicCellImage->TabIndex = 21;
			this->GalvanicCellImage->TabStop = false;
			// 
			// saveButton
			// 
			this->saveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->saveButton->Location = System::Drawing::Point(153, 11);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(135, 80);
			this->saveButton->TabIndex = 22;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::saveButton_Click);
			// 
			// coilButton
			// 
			this->coilButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->coilButton->Location = System::Drawing::Point(153, 214);
			this->coilButton->Name = L"coilButton";
			this->coilButton->Size = System::Drawing::Size(135, 80);
			this->coilButton->TabIndex = 23;
			this->coilButton->Text = L"Катушка";
			this->coilButton->UseVisualStyleBackColor = true;
			this->coilButton->Click += gcnew System::EventHandler(this, &PrincipalScheme::coilButton_Click);
			// 
			// CoilImage
			// 
			this->CoilImage->Location = System::Drawing::Point(25, 473);
			this->CoilImage->Name = L"CoilImage";
			this->CoilImage->Size = System::Drawing::Size(181, 37);
			this->CoilImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->CoilImage->TabIndex = 24;
			this->CoilImage->TabStop = false;
			// 
			// PrincipalScheme
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1079, 478);
			this->Controls->Add(this->CoilImage);
			this->Controls->Add(this->coilButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->GalvanicCellImage);
			this->Controls->Add(this->AmmeterImage);
			this->Controls->Add(this->FuseImage);
			this->Controls->Add(this->LampImage);
			this->Controls->Add(this->galvaniccellButton);
			this->Controls->Add(this->ammeterButton);
			this->Controls->Add(this->fuseButton);
			this->Controls->Add(this->lampButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->networkBox);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->lineButton);
			this->Controls->Add(this->cursorButton);
			this->Controls->Add(this->clearButton);
			this->MinimumSize = System::Drawing::Size(540, 458);
			this->Name = L"PrincipalScheme";
			this->Text = L"PrincipalScheme";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->networkBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LampImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FuseImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AmmeterImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GalvanicCellImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CoilImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: Point DownPosition;
	private: Point CurrentPosition;
	private: Point PrevPosition;
	private: DrawingField drawingField;
	private: int maxnetworkBoxWidth;
	private: int maxnetworkBoxHeight;
	private: int cursorType;

	private: Line^ newLine;
	private: Lamp^ newLamp;
	private: Fuse^ newFuse;
	private: Ammeter^ newAmmeter;
	private: GalvanicCell^ newGalvanicCell;
	private: Coil^ newCoil;

	private: Element^ movingElement;
	private: bool isDown;
	private: Element^ deletingElement;


	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		drawingField.clear();
		draw();

	}
	private: System::Void cursorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = CURSOR;
	}
	private: System::Void lineButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = LINE;
	}
	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = DELETE;
	}
	private: System::Void lampButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = LAMP;
	}
	private: System::Void fuseButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = FUSE;
	}
	private: System::Void ammeterButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = AMMETER;
	}
	private: System::Void galvaniccellButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = GALVANICCELL;
	}
	private: System::Void coilButton_Click(System::Object^ sender, System::EventArgs^ e) {
		cursorType = COIL;
	}
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->Title = "Сохранить";
		save->Filter = "png files (*.png)|*.png|All files (*.*)|*.*";
		if (save->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			networkBox->Image->Save(save->FileName);
		}
	}

	private: System::Void draw() {
		Graphics^ g = Graphics::FromImage(networkBox->Image);
		g->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, networkBox->Width, networkBox->Height);
		drawingField.drawElement(g);
		networkBox->Invalidate();
	}

	private: System::Void networkBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDown = true;
		DownPosition = Point(e->X, e->Y);
		PrevPosition = Point(e->X, e->Y);
		draw();

		switch (cursorType)
		{
		case CURSOR:
			movingElement = drawingField.findElement(e->X, e->Y);
			if (movingElement != nullptr)
			{
				switch (movingElement->type)
				{
				case LINE:
					movingElement = (Line^)movingElement;
					break;
				case LAMP:
					movingElement = (Lamp^)movingElement;
					break;
				case FUSE:
					movingElement = (Fuse^)movingElement;
					break;
				case GALVANICCELL:
					movingElement = (GalvanicCell^)movingElement;
					break;
				case COIL:
					movingElement = (Coil^)movingElement;
					break;
				}
			}
			break;
		case LINE:
			newLine = gcnew Line(DownPosition, DownPosition);
			newLine->draw(Graphics::FromImage(networkBox->Image));
			break;
		case DELETE:
			deletingElement = drawingField.findElement(e->X, e->Y);
			if (deletingElement != nullptr)
				drawingField.deleteElement(deletingElement);
			deletingElement = nullptr;
			break;
		case LAMP:
			newLamp = gcnew Lamp(DownPosition);
			newLamp->draw(Graphics::FromImage(networkBox->Image));
			break;
		case FUSE:
			newFuse = gcnew Fuse(DownPosition);
			newFuse->draw(Graphics::FromImage(networkBox->Image));
			break;
		case AMMETER:
			newAmmeter = gcnew Ammeter(DownPosition);
			newAmmeter->draw(Graphics::FromImage(networkBox->Image));
			break;
		case GALVANICCELL:
			newGalvanicCell = gcnew GalvanicCell(DownPosition);
			newGalvanicCell->draw(Graphics::FromImage(networkBox->Image));
			break;
		case COIL:
			newCoil = gcnew Coil(DownPosition);
			newCoil->draw(Graphics::FromImage(networkBox->Image));
			break;
		}
		networkBox->Invalidate();
	}
	private: System::Void networkBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDown)
		{
			CurrentPosition = Point(e->X, e->Y);
			if (movingElement == nullptr) {
				draw();
				switch (cursorType)
				{
				case CURSOR:
					break;
				case LINE:
					newLine->setFirst(DownPosition);
					newLine->setSecond(CurrentPosition);
					newLine->draw(Graphics::FromImage(networkBox->Image));
					break;
				case LAMP:
					newLamp->setLamp(CurrentPosition);
					newLamp->draw(Graphics::FromImage(networkBox->Image));
					break;
				case FUSE:
					newFuse->setFuse(CurrentPosition);
					newFuse->draw(Graphics::FromImage(networkBox->Image));
					break;
				case AMMETER:
					newAmmeter->setAmmeter(CurrentPosition);
					newAmmeter->draw(Graphics::FromImage(networkBox->Image));
					break;
				case GALVANICCELL:
					newGalvanicCell->setGalvanicCell(CurrentPosition);
					newGalvanicCell->draw(Graphics::FromImage(networkBox->Image));
					break;
				case COIL:
					newCoil->setCoil(CurrentPosition);
					newCoil->draw(Graphics::FromImage(networkBox->Image));
					break;
				}
			}
			else
			{
				changemovingElementPosition();
				draw();
				movingElement->draw(Graphics::FromImage(networkBox->Image));
				PrevPosition = CurrentPosition;
			}
			networkBox->Invalidate();
		}
	}

	private: System::Void networkBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isDown = false;
		switch (cursorType)
		{
		case CURSOR:
			if (movingElement != nullptr) {
				drawingField.addElement(movingElement);
				movingElement = nullptr;
			}
			break;
		case LINE:
			drawingField.addElement(newLine);
			break;
		case LAMP:
			drawingField.addElement(newLamp);
			break;
		case FUSE:
			drawingField.addElement(newFuse);
			break;
		case AMMETER:
			drawingField.addElement(newAmmeter);
			break;
		case GALVANICCELL:
			drawingField.addElement(newGalvanicCell);
			break;
		case COIL:
			drawingField.addElement(newCoil);
			break;
		}
		draw();
	}
	private: System::Void changemovingElementPosition()
	{
		Point p1;
		Point p2;
		int dX = CurrentPosition.X - PrevPosition.X;
		int dY = CurrentPosition.Y - PrevPosition.Y;
		switch (movingElement->type)
		{
		case LINE:
			p1 = ((Line^)movingElement)->getFirst();
			p2 = ((Line^)movingElement)->getSecond();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			if (p2.X + dX < 0 || p2.X + dX > networkBox->Width || p2.Y + dY < 0 || p2.Y + dY > networkBox->Height)
				return;
			((Line^)movingElement)->setFirst(Point(p1.X + dX, p1.Y + dY));
			((Line^)movingElement)->setSecond(Point(p2.X + dX, p2.Y + dY));
			break;
		case LAMP:
			p1 = ((Lamp^)movingElement)->getLamp();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Lamp^)movingElement)->setLamp(p1);
			break;
		case FUSE:
			p1 = ((Fuse^)movingElement)->getFuse();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Fuse^)movingElement)->setFuse(p1);
			break;
		case AMMETER:
			p1 = ((Ammeter^)movingElement)->getAmmeter();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Ammeter^)movingElement)->setAmmeter(p1);
			break;
		case GALVANICCELL:
			p1 = ((GalvanicCell^)movingElement)->getGalvanicCell();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((GalvanicCell^)movingElement)->setGalvanicCell(p1);
			break;
		case COIL:
			p1 = ((Coil^)movingElement)->getCoil();
			if (p1.X + dX < 0 || p1.X + dX > networkBox->Width || p1.Y + dY < 0 || p1.Y + dY > networkBox->Height)
				return;
			p1.X = p1.X + dX;
			p1.Y = p1.Y + dY;
			((Coil^)movingElement)->setCoil(p1);
			break;
			break;
		}
	}

};
}

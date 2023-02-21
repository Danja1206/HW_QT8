#include "filemanager.h"
#include <QDir>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTreeView>
#include <QListView>
#include "mainwindow.h"
#include <QDirIterator>
#include <QDebug>
#include <QPlainTextEdit>
#include <QThread>

FileManager::FileManager(QWidget *parent) : QWidget(parent)
{
    QString sPath = "C:/";
    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(sPath);

    gridLay = new QGridLayout(this);
    this->setLayout(gridLay);
    tree = new QTreeView(this);
    textEdit = new QPlainTextEdit(this);
    gridLay->addWidget(tree, 1, 10, 10, 10);
    gridLay->addWidget(textEdit, 1, 20, 10, 10);
    setMinimumSize(700, 300);
    dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    tree->setModel(dirmodel);
    QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(test(QModelIndex)));


}

void FileManager::test(const QModelIndex& index)
{
    filePath = dirmodel->fileInfo(index).absoluteFilePath();
    list->setRootIndex(filemodel->setRootPath(filePath));
    findFile(filePath, static_cast<MainWindow*>(this->parent())->name());


}

void FileManager::findFile(QString path, QString name)
{
    QFileInfoList hitList;
    QDirIterator it(path, QDirIterator::Subdirectories);
    while (it.hasNext()) {
            QString filename = it.next();
            QFileInfo file(filename);

            if (file.isDir()) {
                continue;

            }

            if (file.fileName().contains(name, Qt::CaseInsensitive)) {
                hitList.append(file);
            }
        }

        foreach (QFileInfo hit, hitList) {
            textEdit->insertPlainText(hit.absoluteFilePath() + "\n");


        }
}

void FileManager::show()
{
   tree->show();
}

void FileManager::hide()
{
   tree->hide();
}

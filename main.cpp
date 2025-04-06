#include "superbox.h"
#include "EnterWindow.h"
#include "CodeCreater.h"
#include <QtWidgets/QApplication>
#include "qfile.h"
#include "qdir.h"
#include "SaveManager.h"
#include "MiscSettingsImporter.h"


int main(int argc, char *argv[]){   
    
    QApplication a(argc, argv);
    MiscSettingsImporter miscSettingImporter;
    SuperBox w;
    EnterWindow enterWindow;
    enterWindow.LoadSuperBox(&w);
    enterWindow.show();
    return a.exec();
}

/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>

/////// can be removed for non-qt-guis ////////////
#include <qapplication.h>
///////////////////////////////////////////////////

#include "session.h"
#include "guiwrapper.h"
#include <net/socket_startup.h>

#include <cstdlib>
#include <ctime>

using namespace std;

class GuiWrapper;

int main( int argc, char **argv )
{
	socket_startup();

	srand( time(0) );

	
	/////// can be removed for non-qt-guis ////////////
	QApplication a( argc, argv );
	a.setStyle(new QPlastiqueStyle);
	Q_INIT_RESOURCE(deck);
	///////////////////////////////////////////////////	

	GuiInterface *myGuiInterface = new GuiWrapper();
	Session theFirst(myGuiInterface);
	myGuiInterface->setSession(&theFirst);

	int retVal = a.exec();

	socket_cleanup();
	return retVal;
}

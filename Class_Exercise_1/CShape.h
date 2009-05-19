#ifndef CSHAPE_H
#define CSHAPE_H

// system includes
#include <iostream>
#include <map>

// project includes
#include "xmlParser.h"

// forward declaration
class CShape;

// typedef
typedef	 CShape* (*CreateFromXmlType )( XMLNode& ) ;	


class CShape 
{
public:
	CShape () : mVisible(true) { gTotalShapes++; } 
	virtual ~CShape() { ; } 

	virtual void	Draw() const = 0;

	static int		CreatedShapes() { return gTotalShapes; }

	virtual void	SaveXml ( XMLNode& ) = 0;

	typedef	std::map< std::string, CreateFromXmlType > CreationMapType;
	typedef	CreationMapType::iterator CreationMapIter;

	static CreationMapType	gCreateFromXmlMap;


private: 
	bool			mVisible;

	static int		gTotalShapes;
};

#endif // CSHAPE_H
//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
//
// Copyright (C) 2002 - 2016, The pgAdmin Development Team
// This software is released under the PostgreSQL Licence
//
// ddRelationshipFigure.h - Item to keep track of foreign keys between tables in a relationship.
//
//////////////////////////////////////////////////////////////////////////

#ifndef DDRELATIONSHIPITEM_H
#define DDRELATIONSHIPITEM_H
#include "hotdraw/figures/hdLineConnection.h"
#include "dd/dditems/figures/ddTableFigure.h"
#include "dd/dditems/figures/ddColumnFigure.h"

class ddRelationshipItem : public hdObject
{
public:
	ddRelationshipItem();
	ddRelationshipItem(ddRelationshipFigure *owner, ddColumnFigure *originalColumn, ddTableFigure *destination, ddColumnOptionType type, ddColumnType colType, ddColumnFigure *existingColumn = NULL);
	~ddRelationshipItem();
	void initRelationshipItemValues(ddRelationshipFigure *owner, ddTableFigure *destination, bool fromExistingColumn, ddColumnFigure *fkCol, ddColumnFigure *sourceCol, wxString initialColName);
	wxString originalStartColName;
	ddColumnFigure *original;
	ddColumnFigure *fkColumn;


	wxString autoGenerateNameForFk();
	void syncAutoFkName();

	ddTableFigure *getDestinationTable()
	{
		return destinationTable;
	};
	bool isAutomaticallyGenerated();
	bool relationIsIdentifying();
	bool relationIsMandatory();
	bool isForeignKeyFromPk();
	wxString sourceTableName();
	wxString destTableName();


private:
	bool fkIsAutoGenerated;
	ddTableFigure *destinationTable;
	ddRelationshipFigure *ownerRel;
	wxString generatedName;   //avoid linux bug
};

#endif

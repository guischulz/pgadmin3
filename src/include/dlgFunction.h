//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// dlgFunction.h - Function property 
//
//////////////////////////////////////////////////////////////////////////


#ifndef __DLG_FUNCTIONPROP
#define __DLG_FUNCTIONPROP

#include "dlgProperty.h"

class pgSchema;
class pgFunction;

class dlgFunction : public dlgSecurityProperty
{
public:
    dlgFunction(frmMain *frame, pgFunction *func, pgSchema *sch);
    int Go(bool modal);

    void CheckChange();
    wxString GetSql();
    pgObject *CreateObject(pgCollection *collection);
    pgObject *GetObject();
    void SetObject(pgObject *obj) { function = (pgFunction*)obj; }

private:
    pgSchema *schema;
    pgFunction *function;

    void OnChangeArgName(wxCommandEvent &ev);
    void OnChangeReturn(wxCommandEvent &ev);
    void OnSelChangeLanguage(wxCommandEvent &ev);
    void OnSelChangeArg(wxListEvent &ev);
    void OnSelChangeType(wxCommandEvent &ev);
    void OnAddArg(wxCommandEvent &ev);
    void OnChangeArg(wxCommandEvent &ev);
    void OnRemoveArg(wxCommandEvent &ev);

    wxString GetArgs(bool withNames=true, bool quoted=false);
    void ReplaceSizer(wxWindow *w, bool isC, int border);

    wxArrayString typOids;
    wxArrayString types;
    wxArrayString argOids;

    wxSizer *libcSizer;
    int typeColNo;

    DECLARE_EVENT_TABLE();
};


#endif

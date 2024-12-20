//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public nomask string Type()
{
    return "item";
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    isLegacy = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setItemData(string name, string description)
{
    Name(name);
    addItemTemplate(description);
}

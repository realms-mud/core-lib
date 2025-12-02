//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pedestal chamber");
    suppressEntryMessage();

    addDescriptionTemplate("this is a very large and cavernous chamber - "
        "easily two hundred yards wide by two hundred yards long.");
}

//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake feature");
    addAdjectives(({ "old" }));

    addDescriptionTemplate("a ##Adjective## oak tree");
}

/////////////////////////////////////////////////////////////////////////////
public void testSuppressEntryMessage()
{
    suppressEntryMessage();
}

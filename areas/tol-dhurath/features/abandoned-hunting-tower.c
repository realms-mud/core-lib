//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("abandoned hunting tower");
    addAlias("hunting tower");
    addDescriptionTemplate("a timber hunting tower leaning against an oak");
    addNearDarkDescriptionTemplate("a broken outline above the trees");
    addLowLightDescriptionTemplate("a leaning timber tower in the trees");
    addDimLightDescriptionTemplate(
        "an abandoned hunting tower with a collapsed lower stair");
    addSomeLightDescriptionTemplate(
        "a timber hunting tower built around the trunk of an old oak");
    addItemTemplate("The lower stair has fallen away, leaving the raised "
        "platform inaccessible. A gap in the roof and the weathered tally "
        "board below it show that the tower has been unused for years.");
}

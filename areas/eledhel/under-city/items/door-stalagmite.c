//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stalagmite");
    addAlias("stone spike");
    addItemTemplate(
        "A thick stalagmite has been levered across the hidden door's "
        "seam. Fresh scrape marks show that it can be rolled aside."
    );
    addDescriptionTemplate(
        "a wedged stalagmite bracing a concealed stone door"
    );
}

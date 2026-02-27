//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spell components");
    addAlias("components");
    addAlias("reagents");
    addAlias("magical supplies");

    addAdjectives(({ "various", "labeled", "exotic", "strange",
        "carefully-stored", "fragrant", "colorful", "mysterious",
        "organized", "dusty" }));

    addDescriptionTemplate("##Adjective## spell components arranged on shelves");

    addItemTemplate(
        "The shelves hold an eclectic collection of spell components "
        "stored in jars, pouches, boxes, and vials. Powdered moonstone "
        "sits beside dried bat wings; vials of mercury neighbor bundles "
        "of wolfsbane. Each container is carefully labeled in a cramped, "
        "precise script, and the air carries an unsettling blend of "
        "strange fragrances."
    );

    addSomeLightDescriptionTemplate(
        "shelves of spell components line the wall — jars, vials, and "
        "pouches of exotic ingredients"
    );
    addDimLightDescriptionTemplate(
        "shelves hold numerous jars and vials of strange substances"
    );
    addLowLightDescriptionTemplate(
        "glass and pottery containers line the shelves"
    );
    addNearDarkDescriptionTemplate(
        "a strange mingling of exotic scents suggests magical components "
        "stored nearby"
    );
}

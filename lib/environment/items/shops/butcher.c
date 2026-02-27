//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("butcher interior");

    addItemTemplate(
        "The butcher's shop is a stark, clean space with whitewashed walls "
        "and a stone-flagged floor. Heavy iron hooks hang from a ceiling beam, "
        "bearing joints of beef, strings of sausages, and plucked fowl. A "
        "thick chopping block stands in the center, its surface deeply scored "
        "from years of use. Behind the counter, shelves hold wrapped cuts of "
        "meat, crocks of rendered fat, and bundles of dried game. Sawdust is "
        "scattered across the floor, and the sharp smell of blood and salt "
        "hangs in the cool air."
    );

    addNearDarkDescriptionTemplate(
        "the butcher's shop is dark and cold, with only the vague outlines "
        "of hanging carcasses visible against the pale walls"
    );
    addLowLightDescriptionTemplate(
        "the butcher's shop is dimly lit, the chopping block and hanging "
        "meats little more than heavy silhouettes"
    );
    addDimLightDescriptionTemplate(
        "soft light reveals the chopping block and the rows of hooks "
        "overhead, their burdens of meat just distinguishable"
    );
    addSomeLightDescriptionTemplate(
        "the butcher's shop is bright enough to see the cuts of meat on "
        "display and the sawdust scattered across the floor"
    );
    addDescriptionTemplate(
        "light fills the butcher's shop, showing the clean whitewashed walls "
        "and the neatly arranged cuts of meat behind the counter"
    );
}

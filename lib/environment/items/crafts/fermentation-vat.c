//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fermentation vat");
    addAlias("fermenter");
    addAlias("brewing vat");

    addAdjectives(({ "large", "wooden", "iron-banded", "sealed",
        "bubbling", "aromatic", "stained", "heavy", "old", "cool" }));

    addDescriptionTemplate("a ##Adjective## fermentation vat sealed with a bung");

    addItemTemplate(
        "The fermentation vat is a tall wooden cask banded with iron, "
        "sealed at the top with a wooden bung fitted with a small pipe "
        "that bubbles steadily as gases escape. The wood is deeply stained "
        "and the air around it is thick with the sweet, complex smell of "
        "fermenting grain and yeast."
    );

    addSomeLightDescriptionTemplate(
        "a fermentation vat stands sealed, its bung pipe bubbling steadily"
    );
    addDimLightDescriptionTemplate(
        "a large sealed cask is visible, faint bubbling sounds coming from "
        "within"
    );
    addLowLightDescriptionTemplate(
        "a large cask stands in the gloom, soft bubbling sounds emanating "
        "from it"
    );
    addNearDarkDescriptionTemplate(
        "a soft bubbling and the sweet smell of fermentation fill the air"
    );
}

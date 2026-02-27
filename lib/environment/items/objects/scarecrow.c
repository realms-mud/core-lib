//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("scarecrow");
    addAlias("straw man");
    addAlias("field scarecrow");

    addAdjectives(({ "ragged", "lopsided", "weathered", "tattered",
        "straw-stuffed", "crooked", "faded", "forlorn", "wind-battered",
        "sun-bleached" }));

    addDescriptionTemplate("a ##Adjective## scarecrow standing in the field");

    addItemTemplate(
        "The scarecrow is lashed to a crooked wooden cross, its body stuffed "
        "with straw that pokes out from every seam. It wears a shapeless hat "
        "and a coat so faded and patched that its original color is anyone's "
        "guess. Its button eyes stare blankly across the field."
    );

    addSomeLightDescriptionTemplate(
        "a scarecrow stands in the field, its ragged coat flapping in the breeze"
    );
    addDimLightDescriptionTemplate(
        "a scarecrow is visible, its silhouette vaguely human against the sky"
    );
    addLowLightDescriptionTemplate(
        "a shape that could be a person stands motionless in the field"
    );
    addNearDarkDescriptionTemplate(
        "a dark figure stands motionless nearby, arms outstretched"
    );
}

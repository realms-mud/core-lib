//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bedroom");

    addAdjectives(({
        "spacious chamber with a canopied bed and heavy stone walls",
        "elegant room adorned with rich tapestries and a grand fireplace",
        "private retreat with arched windows overlooking the castle grounds",
        "sumptuous bedroom featuring carved wooden furniture and velvet drapes",
        "noble sleeping quarters with a vaulted ceiling and ornate chandelier",
        "warm chamber where thick rugs cover the cold flagstone floor"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy chamber where only the faint outline of a large bed and "
        "the glint of metal from a candelabrum are visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit bedroom, where the embers in the fireplace cast flickering "
        "shadows across the canopied bed and stone walls"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the light soft and golden from a few "
        "candles and the fireplace, revealing the rich textures of tapestries "
        "and carved wood"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through arched windows "
        "to illuminate the grand bed, ornate furnishings, and colorful tapestries"
    );
}

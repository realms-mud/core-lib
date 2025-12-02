//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sacred forest glade");

    addAdjectives(({
        "serene glade bathed in soft, dappled sunlight",
        "peaceful clearing surrounded by ancient, towering trees",
        "sacred grove where the air hums with quiet power",
        "enchanted glade, its ground covered in soft moss and vibrant flowers",
        "hallowed forest glade, the trees whispering ancient secrets",
        "tranquil clearing where the earth seems to pulse with life"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowed glade, the trees casting long, dark silhouettes against the dim sky.");
    addLowLightDescriptionTemplate("a dimly lit clearing, soft glimmers of light filtering through the thick canopy above.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the air cool and fragrant with earth and flowers");
    addSomeLightDescriptionTemplate("a softly illuminated ##Adjective##, the sunlight filtering through the leaves in gentle beams");
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone keep");

    addAdjectives(({
        "solid stone chamber where thick walls muffle the sounds of the outside world",
        "fortified room with heavy stone walls and iron-banded doors",
        "sturdy keep interior where centuries of smoke have darkened the vaulted ceiling",
        "austere stone chamber whose bare walls are broken only by narrow windows",
        "imposing room with massive stone blocks fitted together with ancient precision",
        "cold stone interior where drafts whisper through gaps in the shuttered windows",
        "stern keep chamber where the air carries the scent of old stone and lamp oil",
        "fortress room with walls thick enough to withstand a siege engine's blow",
        "weathered stone interior marked by generations of habitation and hard use",
        "formidable keep chamber where iron sconces cast dancing shadows on the walls",
        "stalwart room of dressed stone with deep-set windows and a flagstone floor",
        "enduring keep interior whose heavy timbers and solid masonry speak of permanence",
        "somber stone chamber where the chill never quite leaves the walls",
        "well-built keep room with stout oak beams supporting a vaulted stone ceiling",
        "imposing fortress interior where every surface speaks of defense and duty",
        "time-worn stone chamber whose walls bear the scars of long service",
        "grim keep interior with arrow loops that admit thin shafts of grey light",
        "functional stone room built for strength rather than comfort or beauty",
        "broad stone chamber where the echo of footsteps rings off the bare walls",
        "stalwart keep interior where the cold of the stone seeps into everything"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a stone keep interior swallowed by darkness. The walls are felt "
        "rather than seen, cold and unyielding under the hand. Only the "
        "faintest trace of light from a distant sconce or arrow loop suggests "
        "the size of the space"
    );

    addLowLightDescriptionTemplate(
        "a dimly visible stone keep interior where weak torchlight barely "
        "reaches the vaulted ceiling. The massive walls loom as dark shapes, "
        "and the flagstone floor is a patchwork of faint light and deep shadow"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##. Torchlight flickers across the rough-hewn "
        "stone, picking out the texture of the masonry and the grain of the "
        "heavy oak beams overhead. The air is cool and faintly damp"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. In the full light, the craftsmanship of the "
        "stonework is apparent - each block carefully dressed and fitted, the "
        "mortar lines straight and true. The floor is worn smooth by "
        "generations of boots, and the walls bear the faint ghosts of old "
        "torch marks and the scratches of long-removed fixtures"
    );
}

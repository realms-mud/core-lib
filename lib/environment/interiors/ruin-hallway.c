//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin hallway");

    addAdjectives(({
        "derelict corridor where fallen stones create obstacles to navigate",
        "crumbling hallway where sections of the ceiling have given way",
        "crumbling passage where faded murals peel from moisture-damaged walls",
        "decaying corridor where roots have pushed through the stone floor",
        "ruined hallway where every footstep echoes through the emptiness",
        "long-neglected passage where dust swirls in shafts of broken light",
        "ruined corridor where carved stonework has eroded to unrecognizable forms",
        "deteriorating hallway where puddles form beneath leaking ceilings",
        "shattered passage where wall sconces hang empty and rusted",
        "weathered corridor where wind whistles through cracks in the masonry",
        "silent hallway where only the occasional drip of water breaks the quiet",
        "treacherous passage where fallen debris creates a maze of obstacles",
        "decaying hallway where centuries of footsteps have worn troughs in the stone",
        "skeletal corridor where only the frame of archways remains intact",
        "broken hallway where moss and lichen create patches of slick footing",
        "sundered passage where columns lean at precarious angles",
        "bleak corridor where exposed support beams protrude from crumbling walls",
        "desolate hallway where drifts of debris have accumulated in corners",
        "haunting passage where the outlines of doorways lead to collapsed rooms",
        "ghostly corridor where the scratch of small animals is the only sound"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-dark hallway where your presence disturbs years of silence. "
        "The outlines of fallen debris and damaged walls can barely be discerned "
        "in the gloom, making every step a careful negotiation"
    );

    addLowLightDescriptionTemplate(
        "a shadowy corridor where faint light reveals only the most immediate "
        "hazards - fallen stones, broken flooring, and the occasional gaping hole "
        "where a wall or ceiling has collapsed entirely"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where uncertain light creates misleading "
        "shadows. What might have once been an elegant passage now serves as "
        "little more than a testament to decay and the passage of time"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. The illumination reveals the full extent of "
        "the deterioration - from cracks that spider across the remaining walls "
        "to piles of rubble that were once decorative elements or ceiling segments. "
        "Despite the ruin, the original purpose of connecting different areas "
        "remains evident in the layout"
    );
}

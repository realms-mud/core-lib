//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin");

    addAdjectives(({
        "crumbling structure where time has claimed more than memory remains",
        "crumbling ruin with walls standing like broken teeth against the sky",
        "weathered remnant of some long-forgotten structure or stronghold",
        "collapsed building where nature steadily reclaims what man once built",
        "long-abandoned ruin where wind whistles through gaps in the masonry",
        "skeletal remains of a structure whose purpose has been lost to time",
        "deteriorated building where sunlight penetrates through missing sections",
        "fallen structure where only the strongest foundations still remain",
        "haunting ruin that speaks of civilizations and glories long past",
        "decayed edifice with dangers lurking in every unstable section",
        "fragmentary structure whose original shape can only be guessed at",
        "dilapidated ruin that has weathered countless seasons of neglect",
        "broken building where silence hangs as heavy as the threat of collapse",
        "time-ravaged structure that nature is slowly dismantling stone by stone",
        "spectral ruin whose empty windows stare like hollow eyes at passersby",
        "desolate structure where only ghosts remain to tell its stories",
        "fractured ruin with walls that lean precariously against one another",
        "moss-covered remains that emerge from the landscape like ancient bones",
        "forgotten structure whose secrets lie buried beneath fallen masonry",
        "solitary ruin standing defiant against the inevitable passage of time"
        }));

    useExteriorLighting();

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy ruin whose exact dimensions are lost in darkness. Only the "
        "vaguest outlines of walls and openings can be discerned, creating a "
        "sense of uncertainty and potential danger in every direction"
    );

    addLowLightDescriptionTemplate(
        "a dimly visible ruin where weak light reveals only the most substantial "
        "remaining structures. Shapes loom in the gloom, suggesting walls, "
        "archways, and piles of debris from long-collapsed sections"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where faint illumination casts long shadows "
        "from remaining walls and support structures. The interplay of light and "
        "shadow creates a melancholy beauty among the decay"
    );

    addSomeLightDescriptionTemplate(
        "a well-illuminated ##Adjective##. In clear light, the extent of the "
        "deterioration is fully visible - from crumbling walls to collapsed "
        "roofs, from vegetation taking root in cracks to weathered stones "
        "smoothed by centuries of exposure. What once stood proud now serves "
        "as a monument to impermanence"
    );
}

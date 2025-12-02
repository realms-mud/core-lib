//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood interior");

    addAdjectives(({
        "warm wooden chamber where oak beams cross the ceiling in sturdy arches",
        "rustic interior where every surface bears the mark of a craftsman's hand",
        "cozy wooden room where the scent of pine and hearth smoke mingles",
        "timber-framed chamber with walls of carefully fitted planks",
        "snug wooden interior where years of woodsmoke have darkened the rafters",
        "modest chamber where simple wooden furnishings suit the rough-hewn walls",
        "welcoming wooden room where daylight filters through shuttered windows",
        "practical interior where wooden pegs and joints replace metal nails",
        "weathered wooden chamber that creaks softly with every gust of wind",
        "sturdy room where thick log walls provide shelter from the elements",

        "wooden chamber where carved decorations adorn door frames",
        "spacious timber hall with polished floorboards that reflect the light",
        "welcoming interior where the golden hue of aged wood creates warmth",
        "well-crafted room where not a single board sits uneven or loose",
        "humble wooden chamber where simplicity and function guide design",
        "comfortable interior where wood has been burnished by years of use",
        "charming wooden room where window frames are carved with leaf patterns",
        "secure chamber where thick wooden shutters can bar against the night",
        "pleasant interior where the natural grain of the wood forms patterns",
        "freshly aromatic wooden room where resin still occasionally seeps from knots",

        "lived-in chamber where smoke-blackened beams tell tales of winters past",
        "handsome timber interior with walls arranged in decorative panels",
        "dignified wooden room where wax and oil bring out the wood's rich tones",
        "traditional chamber where generations have added to the wooden details",
        "sheltered interior where tight-fitting boards keep out drafts and damp",
        "functional wooden room where every corner serves some household purpose",
        "distinctive chamber with walls made from honey-colored local timber",
        "homely wooden interior that holds the day's warmth through evening",
        "practical room where wooden surfaces stand ready for daily tasks",
        "carefully joined chamber where the carpenter's skill is evident",

        "time-honored wooden room where tradition guides every construction choice",
        "substantial interior where massive wooden supports frame the space",
        "very accommodating wooden chamber arranged for the needs of daily living",
        "spartan interior where wood fulfills function without needless show",
        "sheltering room where wooden walls and roof wrap occupants in security",
        "well-proportioned chamber where wooden elements balance perfectly",
        "wooden interior that has weathered decades of use gracefully",
        "stout-timbered room designed to stand against weather and time",
        "skillfully crafted chamber where wood has been worked to subtle beauty",
        "sustainable wooden interior built from the surrounding forest's bounty",

        "solid room where wooden walls muffle the sounds from outside",
        "reassuring wooden chamber whose familiar creaks speak of stability",
        "well-ventilated interior where clever wooden shutters control airflow",
        "time-softened room where edges and corners have rounded with wear",
        "handcrafted wooden chamber where each timber tells its own story",
        "domestic interior where wooden fixtures serve generations of needs",
        "straightforward room where honest materials create unpretentious charm",
        "protective wooden chamber whose walls have held against storms and years",
        "interior where wood's natural warmth creates easy comfort",
        "time-tested wooden room where centuries of living have left their mark"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy wooden interior where darkness pools in corners and the scent "
        "of aged timber hangs in the still air. Only the occasional creak of "
        "settling wood breaks the silence, and perhaps the outline of a beam or "
        "doorway can be dimly perceived"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit wooden room where faint light catches on the grain of posts "
        "and rafters. The boundaries of the space are suggested rather than "
        "revealed, with wooden surfaces absorbing what little illumination there is, "
        "leaving much to the imagination"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where the low light brings out the rich "
        "tones and textures of the wooden surfaces. Shadows gather in recesses "
        "and beneath furniture, but the essential character of the timber "
        "construction is evident in the soft illumination"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. The illumination reveals every detail of "
        "the wooden construction, from the grain patterns in the walls to the "
        "skilled joinery at corners and junctions. The wood seems to glow with "
        "an inner warmth, creating an atmosphere of natural comfort and shelter"
    );
}

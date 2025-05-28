//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood interior shop");

    addAdjectives(({
        "cozy wooden shop with sturdy oaken beams overhead and pine shelving",
        "rustic store where the warm scent of cedar and freshly cut timber lingers",
        "charming wooden shop where sunlight streams through shuttered windows",
        "timber-framed store with polished countertops and handcrafted displays",
        "snug wooden establishment where the grain of the walls tells its own story",
        "well-built shop where every board and beam fits with practiced precision",
        "charming wooden store where goods are arranged on spruce shelving",
        "weathered timber shop with walls darkened by years of smoke and polish",
        "crafted wooden interior where joinery details reveal a master's touch",
        "warm shop where the golden hue of pine contrasts with darker walnut accents",
        "welcoming wooden establishment with a plank floor worn smooth by commerce",
        "skillfully constructed shop where even the door hinges are wooden pegs",
        "pine-scented timber store where the subtle scent of wood oils perfumes the air",
        "comfortable wooden shop with a crackling hearth set against one wall",
        "carefully built timber store where not a single nail mars the woodwork",
        "well-kept wooden establishment that gleams with regular applications of wax",
        "skillfully designed shop where wooden carvings decorate beam ends and posts",
        "traditional timber store with shutters that fold back to display wares",
        "modestly adorned wooden shop where function precedes ornamentation",
        "distinctive timber establishment whose wooden walls have aged to a rich patina"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy wooden shop where only the outlines of shelves and counter "
        "can be discerned. The distinctive scent of timber and wax provides more "
        "information than your eyes can gather in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit wooden interior where the grain and knots in the walls and "
        "beams create shadowy patterns. The shopkeeper's wares are mostly hidden "
        "in the gloom, though the solid wooden counter is evident"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where lantern light catches the natural "
        "patterns of the wooden surfaces. The warm glow emphasizes the honey "
        "tones of the timber and creates a welcoming atmosphere despite the low light"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. Sunlight or ample lanterns illuminate the "
        "space completely, revealing the craftsmanship of the wooden interior and "
        "warming the colors of the timber. Every detail of the shop's construction "
        "and merchandise is clearly visible"
    );
}

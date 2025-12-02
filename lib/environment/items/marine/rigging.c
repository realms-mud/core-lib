//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rigging");
    addAdjectives(({ "complex", "tarred", "rope", "web-like", "tangled" }));

    addDescriptionTemplate("a ##Adjective## rigging of ropes and pulleys on the mast");

    addTimeOfDayDescription("dawn", ({
        ". The rigging is slick with dew, ropes glistening in the light",
        ". At dawn, sailors check the rigging for frays and knots",
        ". The ropes creak softly as the ship rocks"
        }));
    addTimeOfDayDescription("noon", ({
        ". The rigging is warm from the sun, ropes drying quickly",
        ". The deck bustles as the rigging is adjusted for the wind",
        ". The rigging hums as the wind whistles through the lines"
        }));
    addTimeOfDayDescription("night", ({
        ". The rigging is barely visible in the darkness",
        ". The air is cool, and the ropes are stiff with dew",
        ". Lanterns cast dim light on the rigging, shadows dancing"
        }));

    addSeasonDescription("spring", ({
        " with the rigging freshly tarred for the new season",
        " as the ropes are checked after winter storms",
        " with the air fresh and the rigging ready for sail"
        }));
    addSeasonDescription("summer", ({
        " with the rigging in constant use, drying quickly in the sun",
        " as the sun beats down, the rigging is a common sight",
        " with the air thick with the scent of tar and hemp"
        }));
    addSeasonDescription("autumn", ({
        " with the rigging checked for wear before winter",
        " as the air turns crisp and the ropes are retied",
        " with the deck quieter, but the rigging still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the rigging rimed with frost, ropes stiff with cold",
        " as only the hardiest sailors brave the chill to climb it",
        " with the rigging covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a web of rigging stretches up the mast, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "rigging glints in the faint light, ropes and pulleys outlined"
    );
    addDimLightDescriptionTemplate(
        "complex rigging stretches from mast to deck, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "well-kept rigging stretches up the mast, ropes taut and ready"
    );
}

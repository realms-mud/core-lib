//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fishing net");
    addAlias("net");
    addAlias("seine");

    addAdjectives(({ "woven", "rope", "broad", "weighted", "fishing" }));
    addDescriptionTemplate("a ##Adjective## fishing net spread out to dry");

    addTimeOfDayDescription("dawn", ({
        ". The fishing net is spread out to dry, damp with morning dew",
        ". At dawn, fishermen check the net for holes and tangled lines",
        ". The net glistens in the soft light, heavy with the night's catch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The net is hauled in, wriggling with fresh fish",
        ". Fishermen mend the net, repairing tears from the morning's work",
        ". The net is coiled and ready for the next cast"
        }));
    addTimeOfDayDescription("noon", ({
        ". The net is left to dry in the sun, fish scales glinting in the mesh",
        ". The air is filled with the scent of fish and salt",
        ". Children watch as the net is cleaned and prepared"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The net is cast again, sinking into the shimmering water",
        ". Fishermen work quickly, pulling the net in before the tide turns",
        ". The net is heavy with the afternoon's catch"
        }));
    addTimeOfDayDescription("evening", ({
        ". The net is rinsed and hung to dry, the day's work nearly done",
        ". The air cools, and the net is packed away for the night",
        ". Gulls gather, hoping for scraps from the day's catch"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The net is coiled and stored in the fading light",
        ". Fishermen finish their tasks, the net lying quiet",
        ". The scent of fish lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The fishing net is left to dry in the cool night air",
        ". Only the faint scent of fish remains as the dock grows quiet",
        ". Lanterns cast dim light on the net, its mesh barely visible"
        }));

    addSeasonDescription("spring", ({
        " with the first big catches of the season filling the net",
        " as the net is mended after winter storms",
        " with the air fresh and the net glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the net in constant use, cast and hauled in all day",
        " as the sun dries the net quickly between catches",
        " with the air thick with the scent of fish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the net packed with the last big catches before winter",
        " as the air turns crisp and the net is checked for wear",
        " with the dock quieter, but the net still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the net rimed with frost, ropes stiff with cold",
        " as only the hardiest fishermen brave the chill to cast the net",
        " with the net stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a fishing net is barely visible, spread out on the dock"
    );
    addLowLightDescriptionTemplate(
        "a fishing net lies on the dock, its mesh hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a heavy fishing net, ropes glistening with moisture, lies ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy fishing net is spread out on the dock, drying in the sun"
    );
    addItemTemplate(
        "The fishing net is woven from strong, tarred twine, its mesh wide "
        "enough to catch fish of all sizes. The net is spread out on the dock, "
        "damp with seawater and glinting with scales. It is well-used but "
        "carefully maintained, and the scent of fish and salt lingers."
    );
}

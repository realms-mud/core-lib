//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cargo net");
    addAlias("net");
    addAlias("loading net");

    addAdjectives(({ "large", "rope", "woven", "cargo", "weighted" }));
    addDescriptionTemplate("a ##Adjective## cargo net for hoisting goods");

    addTimeOfDayDescription("dawn", ({
        ". The cargo net is coiled on the dock, damp with morning dew",
        ". At dawn, dockhands prepare the net for the day's first load",
        ". The net glistens in the soft light, ropes heavy with moisture"
        }));
    addTimeOfDayDescription("morning", ({
        ". The cargo net is hoisted by cranes, filled with crates and barrels",
        ". Dockworkers shout as the net swings overhead, ready for unloading",
        ". The net is checked for wear, knots tightened for safety"
        }));
    addTimeOfDayDescription("noon", ({
        ". The cargo net is busy, swinging between ship and dock",
        ". Sunlight glints off the wet ropes as the net is loaded and unloaded",
        ". The air is filled with the sounds of commerce and creaking wood"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The net is stacked with empty crates, ready for the next shipment",
        ". Dockhands rest in the shade, the net lying idle for a moment",
        ". The net is inspected for damage after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The cargo net is coiled and stored, the day's work nearly done",
        ". The net is damp with evening mist, ropes heavy and cool",
        ". Lanterns cast long shadows over the net as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The net is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the net lying quiet",
        ". The scent of salt and tar lingers as the net is stored"
        }));
    addTimeOfDayDescription("night", ({
        ". The cargo net is left coiled on the dock, silent in the night air",
        ". Only the faint creak of ropes is heard as the net sways in the breeze",
        ". Lanterns cast dim light on the net, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new ropes and fresh knots after winter repairs",
        " as the net is busy with the first shipments of the season",
        " with the air fresh and the net glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the net in constant use, swinging between ship and dock",
        " as the sun dries the ropes quickly between loads",
        " with the air thick with the scent of tar and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the net packed with crates of autumn harvests",
        " as the air turns crisp and the net is checked for wear",
        " with the dock quieter, but the net still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the net rimed with frost, ropes stiff with cold",
        " as only the hardiest workers brave the chill to load cargo",
        " with the net stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a cargo net is barely visible, coiled on the dock"
    );
    addLowLightDescriptionTemplate(
        "a cargo net lies on the dock, its ropes hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a heavy cargo net, ropes glistening with moisture, lies ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy cargo net is coiled on the dock, ready to load or unload cargo"
    );
    addItemTemplate(
        "The cargo net is woven from thick, tarred rope, its mesh large enough "
        "to hold crates and barrels. The net is coiled neatly on the dock, "
        "ready to be hoisted by crane or strong arms. Its ropes are worn but "
        "well-maintained, and the scent of tar and salt lingers."
    );
}

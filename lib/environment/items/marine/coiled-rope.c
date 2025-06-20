//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("coiled rope");
    addAlias("rope");
    addAlias("coil of rope");

    addAdjectives(({ "thick", "tarred", "hemp", "coiled", "dockside" }));
    addDescriptionTemplate("a ##Adjective## coil of rope ready for use");

    addTimeOfDayDescription("dawn", ({
        ". The rope is damp with morning dew, fibers glistening in the light",
        ". At dawn, dockhands check the rope for frays and knots",
        ". The rope is cool and heavy, ready for the day's work"
        }));
    addTimeOfDayDescription("morning", ({
        ". The rope is uncoiled and used to secure boats",
        ". Dockworkers stack coils of rope for the day's tasks",
        ". The air is fresh, and the rope is strong and ready"
        }));
    addTimeOfDayDescription("noon", ({
        ". The rope sits in the sun, fibers drying quickly",
        ". The air is warm, and the rope is used for lifting cargo",
        ". Sailors gather coils of rope for rigging"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The rope is coiled and stored after a busy day",
        ". Dockhands rest nearby, the rope lying ready",
        ". The rope is checked for wear and damage"
        }));
    addTimeOfDayDescription("evening", ({
        ". The rope is packed away, the day's work nearly done",
        ". The air cools, and the rope is damp with evening mist",
        ". Lanterns cast long shadows over the coils of rope"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The rope is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, coils lying quiet",
        ". The scent of tar lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The rope is left coiled on the dock, silent in the night air",
        ". Only the faint scent of tar remains as the dock grows quiet",
        ". Lanterns cast dim light on the coils, their shapes barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new coils arriving for the season's first voyages",
        " as the rope is used for the first rigging of spring",
        " with the air fresh and the rope glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the rope in constant use, drying quickly in the sun",
        " as the sun warms the dock, the rope is a common sight",
        " with the air thick with the scent of tar and hemp"
        }));
    addSeasonDescription("autumn", ({
        " with the rope packed for the last big voyages before winter",
        " as the air turns crisp and the rope is checked for wear",
        " with the dock quieter, but the rope still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the rope rimed with frost, fibers stiff with cold",
        " as only the hardiest workers brave the chill to use rope",
        " with the rope stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a coiled rope is barely visible, stacked on the dock"
    );
    addLowLightDescriptionTemplate(
        "a coil of rope sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy coil of rope, fibers glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made coil of rope is stacked on the dock, ready for use"
    );
    addItemTemplate(
        "The rope is thick and strong, coiled neatly on the dock. Its fibers "
        "are tarred for durability, and the coil is ready for any task-securing "
        "boats, lifting cargo, or rigging sails. The scent of tar and hemp is "
        "strong, and the rope is marked with the insignia of the local merchant."
    );
}

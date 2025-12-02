//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("workshop");

    addAdjectives(({
        "busy workshop with tools hanging from every available space",
        "practical workspace where raw materials await transformation",
        "well-used workshop with a large worktable dominating the center",
        "craftsman's domain filled with the tools and materials of skilled trade",
        "bustling workspace where apprentices hurry between various projects",
        "craftsman's sanctuary where half-finished creations await completion",
        "well-organized workshop where every tool has its designated place",
        "well-used workshop filled with the mingled scents of various materials",
        "master craftsman's space where decades of expertise are evident",
        "productive area where simple components become valuable finished goods",

        "diverse workshop equipped for multiple fabrication needs",
        "chamber where the evidence of daily labor covers every surface",
        "tradesman's domain where secrets of the craft pass from master to apprentice",
        "functional workspace designed for efficiency rather than comfort",
        "skilled artisan's workshop where quality takes precedence over quantity",
        "workspace with shelves of supplies lining the walls",
        "diligent craftsman's shop where patience and precision are paramount",
        "humble workshop where practical knowledge outweighs formal training",
        "spacious work area with multiple stations for different tasks",
        "traditional workshop where methods have been perfected over generations"
    }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy workshop where only the outlines of benches and hanging tools "
        "can be discerned. The lingering scents of materials provide more information "
        "about the craftwork than your eyes can gather in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit workshop, where the shapes of workbenches, tools, and "
        "materials emerge from the shadows. Hints of craftsmanship are visible - "
        "perhaps the gleam of tools or the outline of a project in progress"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, where just enough illumination filters through "
        "to reveal the essential elements of the trade. Shadows gather in corners "
        "and beneath benches, but the primary workspaces are visible enough for "
        "simple tasks to continue"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##. The illumination reveals every detail of the "
        "space dedicated to creation and craft. Tools, materials, works-in-progress, "
        "and the specialized equipment necessary for the trade are all clearly "
        "visible, showcasing the artisan's commitment to their work"
    );
}

//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    mapping catalog = ([
        "impact-theory":"settled-guard",
        "grounded-footwork":"impact-theory",
        "recovery-economy":"grounded-footwork",
        "returning-guard":"recovery-economy",
        "leverage-study":"returning-guard",
        "draining-impact":"leverage-study",
        "momentum-mastery":"draining-impact",
        "unbroken-cadence":"momentum-mastery",
        "staff-fulcrum":"impact-theory",
        "balanced-grip":"staff-fulcrum",
        "sweeping-arc":"balanced-grip",
        "turning-staff":"sweeping-arc",
        "staff-economy":"sweeping-arc",
        "crossbar-defense":"turning-staff",
        "pressing-shaft":"staff-economy",
        "long-reach-geometry":"pressing-shaft",
        "horizon-stroke":"long-reach-geometry",
        "staff-equilibrium":"crossbar-defense",
        "mace-head-alignment":"impact-theory",
        "close-haft-grip":"mace-head-alignment",
        "compact-blow":"close-haft-grip",
        "weighted-rhythm":"compact-blow",
        "mace-recovery":"compact-blow",
        "haft-shelter":"weighted-rhythm",
        "taxing-contact":"mace-recovery",
        "contact-geometry":"taxing-contact",
        "centerline-crush":"contact-geometry",
        "mace-composure":"haft-shelter",
        "hammer-counterweight":"impact-theory",
        "anchored-haft":"hammer-counterweight",
        "falling-head":"anchored-haft",
        "rooted-anvil":"falling-head",
        "hammer-return":"falling-head",
        "braced-recovery":"rooted-anvil",
        "burdening-blow":"hammer-return",
        "anvil-geometry":"burdening-blow",
        "anvil-descent":"anvil-geometry",
        "hammer-poise":"braced-recovery"
    ]);
    Name("bludgeon discipline");
    Description("Controlled impacts and recovery shared by staffs, maces, "
        "and hammers.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/bludgeon/root.c");
    addResearchElement("/guilds/monk/bludgeon/measured-impact.c");
    addResearchElement("/guilds/monk/bludgeon/settled-guard.c");
    TreeRoot("/guilds/monk/bludgeon/root.c");
    addChild("/guilds/monk/bludgeon/measured-impact.c",
        "/guilds/monk/bludgeon/root.c");
    addChild("/guilds/monk/bludgeon/settled-guard.c",
        "/guilds/monk/bludgeon/measured-impact.c");

    foreach (string item in m_indices(catalog))
    {
        addResearchElement("/guilds/monk/bludgeon/" + item + ".c");
    }
    foreach (string item, string parent in catalog)
    {
        addChild("/guilds/monk/bludgeon/" + item + ".c",
            "/guilds/monk/bludgeon/" + parent + ".c");
    }
}

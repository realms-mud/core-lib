//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected void Setup()
{
    Name("unarmed discipline");
    Description("Deliberate unarmed forms, demonstrated combat practice, "
        "and balanced recovery.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addResearchElement("/guilds/monk/unarmed/root.c");
    addResearchElement("/guilds/monk/unarmed/measured-palm.c");
    addResearchElement("/guilds/monk/unarmed/balanced-recovery.c");
    TreeRoot("/guilds/monk/unarmed/root.c");
    addChild("/guilds/monk/unarmed/measured-palm.c",
        "/guilds/monk/unarmed/root.c");
    addChild("/guilds/monk/unarmed/balanced-recovery.c",
        "/guilds/monk/unarmed/measured-palm.c");
    mapping additions = ([
        "quiet-footwork":"measured-palm",
        "open-hand-guard":"measured-palm",
        "joint-conditioning":"open-hand-guard",
        "guarded-breath":"quiet-footwork",
        "hand-alignment":"measured-palm",
        "grounded-base":"joint-conditioning",
        "supple-form":"quiet-footwork",
        "centered-vitality":"grounded-base",
        "patient-recovery":"balanced-recovery",
        "vital-reading":"guarded-breath",
        "iron-body":"centered-vitality",
        "still-heart":"vital-reading",
        "driving-elbow":"hand-alignment",
        "disrupting-knee":"open-hand-guard",
        "rising-heel":"supple-form",
        "sapping-palm":"driving-elbow",
        "hammer-fist":"grounded-base",
        "centering-breath":"guarded-breath",
        "crushing-embrace":"disrupting-knee",
        "meridian-strike":"meridian-lore",
        "empty-hand":"hammer-fist",
        "returning-breath":"breath-economy",
        "elbow-anatomy":"driving-elbow",
        "knee-leverage":"disrupting-knee",
        "heel-trajectory":"rising-heel",
        "meridian-lore":"sapping-palm",
        "fist-compression":"hammer-fist",
        "restorative-breath":"centering-breath",
        "grappling-mechanics":"crushing-embrace",
        "pulse-mapping":"meridian-strike",
        "empty-hand-theory":"empty-hand",
        "breath-economy":"restorative-breath",
        "returning-rhythm":"returning-breath",
        "finishing-economy":"empty-hand-theory",
        "crane-stance":"quiet-footwork",
        "tiger-stance":"driving-elbow",
        "stone-stance":"grounded-base",
        "flowing-stance":"supple-form"
    ]);
    foreach(string item in m_indices(additions))
    {
        addResearchElement("/guilds/monk/unarmed/" + item + ".c");
    }
    foreach(string item in m_indices(additions))
    {
        addChild("/guilds/monk/unarmed/" + item + ".c",
            "/guilds/monk/unarmed/" + additions[item] + ".c");
    }
}

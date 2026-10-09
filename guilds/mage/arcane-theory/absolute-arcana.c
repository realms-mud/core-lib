//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Arcana");
    addSpecification("source", "mage");
    addSpecification("description", "Absolute command of arcane theory boosts all magical abilities.");

    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 61]));
    addPrerequisite("/guilds/mage/arcane-theory/archmage-constitution.c",
        (["type": "research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arcane Bolt": 10,
        "Force Burst": 10,
        "Mana Strike": 10,
        "Arcane Explosion": 10,
        "Force Shatter": 10,
        "Mana Surge": 10,
        "Arcane Lance": 10,
        "Arcane Torrent": 10,
        "Mana Storm": 10,
        "Arcane Annihilation": 10,
        "Alter Form": 10,
        "Warp Flesh": 10,
        "Transmute Matter": 10,
        "Reshape Body": 10,
        "Flesh Contortion": 10,
        "Matter Shift": 10,
        "Body Warp": 10,
        "Cellular Disruption": 10,
        "Total Transformation": 10,
        "Final Reckoning": 10,
        "Arcane Drain": 10,
        "Force Redirection": 10,
        "Vital Siphon": 10,
        "Energy Absorption": 10,
        "Force Inversion": 10,
        "Life Tap": 10,
        "Arcane Void": 10,
        "Force Collapse": 10,
        "Essence Drain": 10,
        "Total Drain": 10,
        "Psychic Lance": 10,
        "Thought Shatter": 10,
        "Psionic Bolt": 10,
        "Mind Rend": 10,
        "Neural Shatter": 10,
        "Psionic Surge": 10,
        "Mindstorm": 10,
        "Psychic Collapse": 10,
        "Neural Annihilation": 10,
        "Total Mind Collapse": 10,
        "Arcane Sight": 10,
        "Reveal Weakness": 10,
        "Foresight Bolt": 10,
        "Expose Vulnerability": 10,
        "Prescient Strike": 10,
        "Oracle Bolt": 10,
        "True Sight Blast": 10,
        "Destiny Strike": 10,
        "Unveiled Doom": 10,
        "Total Revelation": 10,
        "Keen Strike": 10,
        "Dulled Senses": 10,
        "Perceptive Bolt": 10,
        "Blinding Surge": 10,
        "Sensory Disruption": 10,
        "Heightened Bolt": 10,
        "Overload Senses": 10,
        "Perception Rend": 10,
        "Sensory Annihilation": 10,
        "Total Sensory Collapse": 10,
    ]));
    addSpecification("affected research type", "percentage");
}
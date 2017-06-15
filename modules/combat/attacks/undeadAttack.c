//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();
    setDamageType("undead");
    addHitDictionary(({
        "eviscerate", "shred", "menace", "flatten", "crush", "rip", }));

    addSimileDictionary(({
        "with a deathly howl", "leaving a stench of decay", }));
        
    addMissMessage("##AttackerName## ##Infinitive::intone##, `Klaatu..."
        " verata... n... Necktie. Nectar. Nickel. Noodle.'");
    
    addHitMessage("##AttackerName## ##Infinitive::intone## menacing words "
        "of death and ##HitDictionary## ##TargetName## ##SimileDictionary##.",
        "1-50");
}




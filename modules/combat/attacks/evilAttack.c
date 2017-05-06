inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("evil");
    addHitDictionary(({
        "eviscerate", "slam", "menace", "flatten", "crush", "slam",
        "crash", "gut", "rip", "shred", "gouge" }));

    addSimileDictionary(({
        "with a bolt of sickly green energy", "with tendrils of black energy",
        "and demonic howls are heard in the air" }));
        
    addMissMessage("##AttackerName## ##Infinitive::look## very menacing! But "
        "that's about it.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "+
        "##SimileDictionary##.", "1-50");
}




inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("good");
    addHitDictionary(({
        "smite", "slam", "punish", "flatten", "crush", "hammer", "pound",
        "maul" }));

    addSimileDictionary(({
        "with a pure silvery force", "with a blast of blinding white light",
        "with a shining blade of silver light" }));
        
    addMissMessage("##AttackerName## ##Infinitive::smile## pleasantly "+
        "at ##TargetName##.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-50");
}



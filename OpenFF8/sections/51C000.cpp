#include "../structures.h"
#include "../memory.h"
// mov eax,dword ptr ds:[1D9CE00]
// mov ecx,dword ptr ss:[esp+4]
// mov edx,dword ptr ss:[esp+8]
// lea eax,dword ptr ds:[eax+eax*2]
// add edx,7FF
// shr edx,B
// mov dword ptr ds:[eax*4+1D9CE08],ecx
// mov eax,dword ptr ds:[1D9CE00]
// mov ecx,dword ptr ss:[esp+C]
// lea eax,dword ptr ds:[eax+eax*2]
// shl edx,B
// mov dword ptr ds:[eax*4+1D9CE0C],edx
// mov eax,dword ptr ds:[1D9CE00]
// shr ecx,2
// lea edx,dword ptr ds:[eax+eax*2]
// mov dword ptr ds:[edx*4+1D9CE10],ecx
// mov eax,dword ptr ds:[1D9CE00]
// mov ecx,eax
// inc eax
// cmp ecx,10
// mov dword ptr ds:[1D9CE00],eax
// jl ff8_en.51C106
// push 78
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// ret 



// push edi
// xor ecx,ecx
// mov edx,FFFE
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// cmp al,FF
// je ff8_en.51C158
// and eax,FF
// lea edi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edi*2]
// cmp word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],0
// jne ff8_en.51C158
// mov word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],1
// xor eax,eax
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// lea edi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edi*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_STATUS>],dx
// inc ecx
// cmp ecx,3
// jl ff8_en.51C118
// pop edi
// ret 



int SCRIPT_NOP(FieldEntity& entity, int arg) {
    return 0;
}



void SCRIPT_CAL_ADD(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] + entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_SUB(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] - entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_NEGATE(FieldEntity& entity) {
    entity.stack[entity.stack_count] = -entity.stack[entity.stack_count];
}



void SCRIPT_CAL_MUL(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] * entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_DIV(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] / entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_MOD(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] % entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_EQUAL(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] == entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_GREATER(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] > entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_GREATEROREQUAL(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] >= entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_LESS(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] < entity.stack[entity.stack_count + 1];
}


 
void SCRIPT_CAL_LESSOREQUAL(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] <= entity.stack[entity.stack_count + 1];
}


 
void SCRIPT_CAL_NOTEQUAL(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] != entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_AND(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] & entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_OR(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] | entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_XOR(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] ^ entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_BITWISENOT(FieldEntity& entity) {
    entity.stack[entity.stack_count] = ~entity.stack[entity.stack_count];
}



void SCRIPT_CAL_BITSHIFTRIGHT(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] >> entity.stack[entity.stack_count + 1];
}



void SCRIPT_CAL_BITSHIFTLEFT(FieldEntity& entity) {
    entity.stack_count--;
    entity.stack[entity.stack_count] = entity.stack[entity.stack_count] << entity.stack[entity.stack_count + 1];
}



void (*Script_CALoperaion[])(FieldEntity& entity) = { SCRIPT_CAL_ADD, SCRIPT_CAL_SUB, SCRIPT_CAL_MUL, SCRIPT_CAL_DIV, SCRIPT_CAL_MOD, SCRIPT_CAL_NEGATE,
                                                      SCRIPT_CAL_EQUAL, SCRIPT_CAL_GREATER, SCRIPT_CAL_GREATEROREQUAL, SCRIPT_CAL_LESS, SCRIPT_CAL_LESSOREQUAL, SCRIPT_CAL_NOTEQUAL,
                                                      SCRIPT_CAL_AND, SCRIPT_CAL_OR, SCRIPT_CAL_XOR, SCRIPT_CAL_BITWISENOT, SCRIPT_CAL_BITSHIFTRIGHT, SCRIPT_CAL_BITSHIFTLEFT };



int SCRIPT_CAL(FieldEntity& entity, int arg) {
    Script_CALoperaion[arg](entity);
    return 2;
}



int SCRIPT_JMP(FieldEntity& entity, int arg) {
    entity.instruction_pointer += arg;
    return 4;
}



int SCRIPT_JPF(FieldEntity& entity, int arg) {
    entity.stack_count--;
    if (entity.stack[entity.stack_count + 1] == 0) {
        entity.instruction_pointer += arg;
        return 4;
    }
    else {
        return 2;
    }
}



// mov eax,dword ptr ss:[esp+4]
// xor edx,edx - edx = 0
// mov cl,byte ptr ds:[eax+184]
// mov dx,word ptr ds:[eax+176]
// inc cl
// inc edx
// mov byte ptr ds:[eax+184],cl
// movsx ecx,cl
// mov dword ptr ds:[eax+ecx*4],edx
// mov edx,dword ptr ss:[esp+8]
// mov ecx,dword ptr ds:[1D9D0E4]
// mov dx,word ptr ds:[ecx+edx*2]
// mov word ptr ds:[eax+176],dx
// mov eax,4
// ret 
int SCRIPT_GJMP(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// lea esi,dword ptr ds:[eax+140]
// mov edx,8
// mov ecx,esi
// mov bl,byte ptr ds:[eax+184]
// add ecx,4
// inc bl
// dec edx
// movsx edi,bl
// mov byte ptr ds:[eax+184],bl
// mov ebx,dword ptr ds:[ecx-4]
// mov dword ptr ds:[eax+edi*4],ebx
// mov dword ptr ds:[ecx-4],0
// jne ff8_en.51C584
// test byte ptr ds:[eax+160],20
// je ff8_en.51C5B7
// mov dword ptr ds:[esi],1
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_LBL(FieldEntity& entity, int arg) {
    return 0;
}



// push ebx
// push ebp
// push esi
// mov esi,dword ptr ss:[esp+10]
// push edi
// mov ecx,8
// lea ebp,dword ptr ds:[esi+140]
// mov eax,ebp
// movsx edx,byte ptr ds:[esi+184]
// add eax,4
// mov edx,dword ptr ds:[esi+edx*4]
// mov dword ptr ds:[eax-4],edx
// mov dl,byte ptr ds:[esi+184]
// dec dl
// dec ecx
// mov byte ptr ds:[esi+184],dl
// jne ff8_en.51C5D5
// mov ebx,dword ptr ds:[esi+160]
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+174]
// and ebx,FFFFFFDF
// mov dword ptr ds:[esi+160],ebx
// mov eax,ebx
// mov bl,1
// shl bl,cl
// mov cl,byte ptr ds:[esi+175]
// or cl,bl
// mov ebx,dword ptr ss:[esp+18]
// mov byte ptr ds:[esi+175],cl
// mov ecx,ebx
// sub ecx,8
// je ff8_en.51C831
// dec ecx
// je ff8_en.51C811
// test eax,eax.10000000
// je ff8_en.51C777
// test eax,10000
// je ff8_en.51C777
// mov edx,dword ptr ds:[esi+1C4]
// mov ecx,dword ptr ds:[esi+1C0]
// mov dword ptr ds:[esi+1B8],edx
// mov dx,word ptr ds:[esi+21C]
// mov dword ptr ds:[esi+1B4],ecx
// mov ecx,dword ptr ds:[esi+1C8]
// mov word ptr ds:[esi+21A],dx
// mov dx,word ptr ds:[esi+202]
// and eax,FFFEFFFF
// xor edi,edi
// test eax,40000
// mov dword ptr ds:[esi+1BC],ecx
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],di
// mov word ptr ds:[esi+1FE],dx
// mov dword ptr ds:[esi+160],eax
// je ff8_en.51C777
// movsx ecx,word ptr ds:[1CE476A]
// movsx edx,dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// lea eax,dword ptr ds:[eax+eax*2]
// lea ecx,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[ecx+ecx*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.51C6EA
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.51C75F
// jmp ff8_en.51C6FA
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.51C75F
// xor bx,bx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov bl,al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov ebx,dword ptr ss:[esp+18]
// mov word ptr ds:[esi+206],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov word ptr ds:[esi+20A],di
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],di
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// xor eax,eax
// xor ecx,ecx
// mov al,byte ptr ds:[esi+174]
// mov word ptr ds:[esi+eax*2+164],FFFF
// mov cl,byte ptr ds:[esi+174]
// dec ecx
// cmp ecx,ebx
// jle ff8_en.51C7BB
// lea eax,dword ptr ds:[esi+ecx*2+164]
// cmp word ptr ds:[eax],FFFF
// je ff8_en.51C7B3
// mov dl,1
// shl dl,cl
// or byte ptr ds:[esi+175],dl
// mov word ptr ds:[eax],FFFF
// dec ecx
// sub eax,2
// cmp ecx,ebx
// jg ff8_en.51C79D
// mov al,byte ptr ds:[esi+ebx+17C]
// mov ecx,8
// add al,8
// mov byte ptr ds:[esi+184],al
// mov eax,ebp
// movsx edx,byte ptr ds:[esi+184]
// add eax,4
// mov edx,dword ptr ds:[esi+edx*4]
// mov dword ptr ds:[eax-4],edx
// mov dl,byte ptr ds:[esi+184]
// dec dl
// dec ecx
// mov byte ptr ds:[esi+184],dl
// jne ff8_en.51C7D1
// mov ax,word ptr ds:[esi+ebx*2+164]
// mov byte ptr ds:[esi+174],bl
// mov word ptr ds:[esi+176],ax
// pop edi
// pop esi
// pop ebp
// mov eax,4
// pop ebx
// ret 
// movsx ecx,dl
// dec dl
// pop edi
// mov ax,word ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],dl
// mov word ptr ds:[esi+176],ax
// pop esi
// pop ebp
// mov eax,4
// pop ebx
// ret 
// xor edi,edi
// test eax,eax.10000000
// je ff8_en.51C92F
// test eax,10000
// je ff8_en.51C92F
// mov edx,dword ptr ds:[esi+1C4]
// mov ecx,dword ptr ds:[esi+1C0]
// mov dword ptr ds:[esi+1B8],edx
// mov dx,word ptr ds:[esi+21C]
// mov dword ptr ds:[esi+1B4],ecx
// mov ecx,dword ptr ds:[esi+1C8]
// mov word ptr ds:[esi+21A],dx
// mov dx,word ptr ds:[esi+202]
// and eax,FFFEFFFF
// mov dword ptr ds:[esi+1BC],ecx
// test eax,40000
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],di
// mov word ptr ds:[esi+1FE],dx
// mov dword ptr ds:[esi+160],eax
// je ff8_en.51C92F
// movsx ecx,word ptr ds:[1CE476A]
// movsx edx,dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.51C8E9
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.51C917
// movzx ax,al
// push eax
// jmp ff8_en.51C8FF
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.51C917
// xor cx,cx
// mov cl,al
// push ecx
// push esi
// call ff8_en.526320
// mov eax,dword ptr ds:[esi+160]
// add esp,8
// or ah,20
// mov dword ptr ds:[esi+160],eax
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],di
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// xor edx,edx
// xor eax,eax
// mov dl,byte ptr ds:[esi+174]
// mov word ptr ds:[esi+edx*2+164],FFFF
// mov al,byte ptr ds:[esi+174]
// dec eax
// js ff8_en.51C981
// lea ecx,dword ptr ds:[esi+eax*2+164]
// cmp word ptr ds:[ecx],FFFF
// jne ff8_en.51C96C
// dec eax
// sub ecx,2
// cmp eax,edi
// jge ff8_en.51C953
// pop edi
// pop esi
// pop ebp
// mov eax,4
// pop ebx
// ret 
// mov cx,word ptr ds:[esi+eax*2+164]
// mov byte ptr ds:[esi+174],al
// mov word ptr ds:[esi+176],cx
// pop edi
// pop esi
// pop ebp
// mov eax,4
// pop ebx
// ret 
int SCRIPT_RET(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 4
// push eax
// inc byte ptr ds:[esi+184]
// call ff8_en.51C9C0
// movsx ecx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+ecx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHN_L(FieldEntity& entity, int arg) {
    //entity.stack_count++;
    //entity.stack[entity.stack_count] = Sub51c9c0(arg, 4)
    return 2;
}



// mov eax,dword ptr ss:[esp+8]
// cmp eax,7
// ja ff8_en.51CA7F
// jmp dword ptr ds:[eax*4+51CA84]
// mov eax,dword ptr ss:[esp+4]
// and eax,1
// jmp ff8_en.51C9E1
// mov eax,dword ptr ss:[esp+4]
// cmp eax,FFFFFF80
// jge ff8_en.51C9EC
// mov eax,FFFFFF80
// ret 
// cmp eax,7F
// jl ff8_en.51CA83
// mov eax,7F
// ret 
// mov eax,dword ptr ss:[esp+4]
// cmp eax,FFFF8000
// jge ff8_en.51CA0C
// mov eax,FFFF8000
// ret 
// cmp eax,7FFF
// jl ff8_en.51CA83
// mov eax,7FFF
// ret 
// mov eax,dword ptr ss:[esp+4]
// cmp eax,FF800000
// jge ff8_en.51CA2A
// mov eax,FF800000
// ret 
// cmp eax,ff8_en.7FFFFF
// jl ff8_en.51CA83
// mov eax,ff8_en.7FFFFF
// ret 
// mov eax,dword ptr ss:[esp+4]
// test eax,eax
// jge ff8_en.51CA42
// xor eax,eax
// ret 
// cmp eax,FF
// jl ff8_en.51CA83
// mov eax,FF
// ret 
// mov eax,dword ptr ss:[esp+4]
// test eax,eax
// jge ff8_en.51CA5A
// xor eax,eax
// ret 
// cmp eax,FFFF
// jl ff8_en.51CA83
// mov eax,FFFF
// ret 
// mov eax,dword ptr ss:[esp+4]
// test eax,eax
// jge ff8_en.51CA72
// xor eax,eax
// ret 
// cmp eax,ff8_en.FFFFFF
// jl ff8_en.51CA83
// mov eax,ff8_en.FFFFFF
// ret 
// mov eax,dword ptr ss:[esp+4]
// ret 



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 4
// mov cl,byte ptr ds:[esi+184]
// inc cl
// mov byte ptr ds:[esi+184],cl
// mov ecx,dword ptr ds:[esi+eax*4+140]
// push ecx
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret
int SCRIPT_PSHI_L(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// xor eax,eax
// push 5
// mov cl,byte ptr ds:[esi+184]
// inc cl
// mov byte ptr ds:[esi+184],cl
// mov ecx,dword ptr ss:[esp+10]
// mov al,byte ptr ds:[ecx+<SG_FIELD_VARS>]
// push eax
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHM_B(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// xor eax,eax
// push 6
// mov cl,byte ptr ds:[esi+184]
// inc cl
// mov byte ptr ds:[esi+184],cl
// mov ecx,dword ptr ss:[esp+10]
// mov ax,word ptr ds:[ecx+<SG_FIELD_VARS>]
// push eax
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHM_W(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 7
// mov cl,byte ptr ds:[esi+184]
// inc cl
// mov byte ptr ds:[esi+184],cl
// mov ecx,dword ptr ds:[eax+<SG_FIELD_VARS>]
// push ecx
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHM_L(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 2
// inc byte ptr ds:[esi+184]
// movsx ecx,byte ptr ds:[eax+<SG_FIELD_VARS>]
// push ecx
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHSM_B(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 3
// inc byte ptr ds:[esi+184]
// movsx ecx,word ptr ds:[eax+<SG_FIELD_VARS>]
// push ecx
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHSM_W(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 4
// mov cl,byte ptr ds:[esi+184]
// inc cl
// mov byte ptr ds:[esi+184],cl
// mov ecx,dword ptr ds:[eax+<SG_FIELD_VARS>]
// push ecx
// call ff8_en.51C9C0
// movsx edx,byte ptr ds:[esi+184]
// add esp,8
// mov dword ptr ds:[esi+edx*4],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_PSHSM_L(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// movsx ecx,byte ptr ds:[eax+184]
// mov edx,dword ptr ds:[eax+ecx*4]
// mov ecx,dword ptr ss:[esp+8]
// mov dword ptr ds:[eax+ecx*4+140],edx
// mov cl,byte ptr ds:[eax+184]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov eax,2
// ret 
int SCRIPT_POPI_L(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[esi+<SG_FIELD_VARS>],dl
// mov eax,2
// pop esi
// ret 
int SCRIPT_POPM_B(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[esi+<SG_FIELD_VARS>],dx
// mov eax,2
// pop esi
// ret 
int SCRIPT_POPM_W(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov dword ptr ds:[esi+<SG_FIELD_VARS>],edx
// mov eax,2
// pop esi
// ret 
int SCRIPT_POPM_L(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov edx,dword ptr ss:[esp+8]
// mov cl,byte ptr ds:[eax+184]
// inc cl
// mov byte ptr ds:[eax+184],cl
// movsx ecx,cl
// mov dword ptr ds:[eax+ecx*4],edx
// mov eax,2
// ret 
int SCRIPT_PSHAC(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// dec al
// mov esi,dword ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// movsx ecx,al
// dec al
// mov ebx,dword ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov eax,dword ptr ss:[esp+14]
// mov ecx,dword ptr ds:[eax*4+1D9D020]
// test ecx,ecx
// je ff8_en.51CEB8
// mov al,byte ptr ds:[<current_entity>]
// cmp al,byte ptr ds:[ecx+256]
// jne ff8_en.51CDB7
// inc word ptr ds:[edx+176]
// mov eax,4
// jmp ff8_en.51CDBC
// mov eax,3
// mov edx,ebx
// mov dword ptr ss:[esp+10],eax
// and edx,FF
// cmp word ptr ds:[ecx+edx*2+164],FFFF
// lea ebp,dword ptr ds:[ecx+edx*2+164]
// jne ff8_en.51CEBD
// mov dl,byte ptr ds:[ecx+184]
// xor eax,eax
// mov al,byte ptr ds:[ecx+174]
// push edi
// mov edi,dword ptr ds:[1D9D0E4]
// mov byte ptr ds:[eax+ecx+17C],dl
// mov dl,byte ptr ds:[ecx+174]
// cmp bl,dl
// jbe ff8_en.51CEA1
// mov ax,word ptr ds:[ecx+176]
// and edx,FF
// mov word ptr ds:[ecx+edx*2+164],ax
// mov edx,esi
// and edx,FFFF
// mov byte ptr ds:[ecx+174],bl
// mov ax,word ptr ds:[edi+edx*2]
// mov edx,dword ptr ds:[ecx+160]
// test edx,eax.10000000
// mov word ptr ds:[ecx+176],ax
// je ff8_en.51CEA1
// cmp byte ptr ds:[ecx+23C],1
// jne ff8_en.51CEA1
// mov eax,dword ptr ds:[ecx+1B4]
// or edx,10000
// mov dword ptr ds:[ecx+1C0],eax
// mov eax,dword ptr ds:[ecx+1B8]
// mov dword ptr ds:[ecx+1C4],eax
// mov eax,dword ptr ds:[ecx+1BC]
// mov dword ptr ds:[ecx+1C8],eax
// mov ax,word ptr ds:[ecx+21A]
// mov word ptr ds:[ecx+21C],ax
// mov ax,word ptr ds:[ecx+1FE]
// mov byte ptr ds:[ecx+23C],0
// mov word ptr ds:[ecx+202],ax
// mov dword ptr ds:[ecx+160],edx
// mov eax,dword ptr ss:[esp+14]
// and esi,FFFF
// mov cx,word ptr ds:[edi+esi*2]
// pop edi
// mov word ptr ss:[ebp],cx
// pop esi
// pop ebp
// pop ebx
// ret 
// mov eax,3
// pop esi
// pop ebp
// pop ebx
// ret 
int SCRIPT_REQ(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push ebx
// push ebp
// push esi
// mov eax,dword ptr ds:[eax*4+1D9D020]
// push edi
// test eax,eax
// je ff8_en.51D03A
// mov edi,dword ptr ss:[esp+14]
// mov ebx,1
// mov cl,byte ptr ds:[edi+184]
// mov byte ptr ss:[esp+18],cl
// movsx ecx,cl
// mov edx,dword ptr ds:[edi+ecx*4-4]
// lea esi,dword ptr ds:[edi+ecx*4]
// mov cl,byte ptr ds:[edi+174]
// shl ebx,cl
// mov cl,byte ptr ds:[edi+175]
// test cl,bl
// je ff8_en.51D00E
// mov ecx,edx
// mov esi,dword ptr ds:[esi]
// and ecx,FF
// cmp word ptr ds:[eax+ecx*2+164],FFFF
// lea ebp,dword ptr ds:[eax+ecx*2+164]
// jne ff8_en.51D01A
// mov bl,byte ptr ds:[eax+184]
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// mov edi,dword ptr ds:[1D9D0E4]
// mov byte ptr ds:[ecx+eax+17C],bl
// mov cl,byte ptr ds:[eax+174]
// cmp dl,cl
// jbe ff8_en.51CFFC
// mov bx,word ptr ds:[eax+176]
// and ecx,FF
// mov word ptr ds:[eax+ecx*2+164],bx
// mov ecx,esi
// and ecx,FFFF
// mov byte ptr ds:[eax+174],dl
// mov cx,word ptr ds:[edi+ecx*2]
// mov word ptr ds:[eax+176],cx
// mov ecx,dword ptr ds:[eax+160]
// test ecx,eax.10000000
// je ff8_en.51CFFC
// cmp byte ptr ds:[eax+23C],1
// jne ff8_en.51CFFC
// mov ebx,dword ptr ds:[eax+1B4]
// or ecx,10000
// mov dword ptr ds:[eax+1C0],ebx
// mov ebx,dword ptr ds:[eax+1B8]
// mov dword ptr ds:[eax+1C4],ebx
// mov ebx,dword ptr ds:[eax+1BC]
// mov dword ptr ds:[eax+1C8],ebx
// mov bx,word ptr ds:[eax+21A]
// mov word ptr ds:[eax+21C],bx
// mov bx,word ptr ds:[eax+1FE]
// mov byte ptr ds:[eax+23C],0
// mov word ptr ds:[eax+202],bx
// mov dword ptr ds:[eax+160],ecx
// and esi,FFFF
// mov cx,word ptr ds:[edi+esi*2]
// mov edi,dword ptr ss:[esp+14]
// mov word ptr ss:[ebp],cx
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// cmp ecx,edx
// jne ff8_en.51D030
// mov al,byte ptr ss:[esp+18]
// sub al,2
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// pop ebp
// mov eax,3
// pop ebx
// ret 
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// ret 
// mov eax,dword ptr ss:[esp+14]
// pop edi
// pop esi
// pop ebp
// mov cl,byte ptr ds:[eax+184]
// pop ebx
// add cl,FE
// mov byte ptr ds:[eax+184],cl
// mov eax,3
// ret 
int SCRIPT_REQSW(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+8]
// push ebx
// push ebp
// push esi
// mov eax,dword ptr ds:[eax*4+1D9D020]
// push edi
// test eax,eax
// je ff8_en.51D1CA
// mov edi,dword ptr ss:[esp+14]
// mov ebx,1
// mov cl,byte ptr ds:[edi+184]
// mov byte ptr ss:[esp+18],cl
// movsx ecx,cl
// mov edx,dword ptr ds:[edi+ecx*4-4]
// lea esi,dword ptr ds:[edi+ecx*4]
// mov cl,byte ptr ds:[edi+174]
// shl ebx,cl
// mov cl,byte ptr ds:[edi+175]
// test cl,bl
// je ff8_en.51D19E
// mov ecx,edx
// mov esi,dword ptr ds:[esi]
// and ecx,FF
// cmp word ptr ds:[eax+ecx*2+164],FFFF
// lea ebp,dword ptr ds:[eax+ecx*2+164]
// jne ff8_en.51D1AA
// mov bl,byte ptr ds:[eax+184]
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// mov edi,dword ptr ds:[1D9D0E4]
// mov byte ptr ds:[ecx+eax+17C],bl
// mov cl,byte ptr ds:[eax+174]
// cmp dl,cl
// jbe ff8_en.51D18C
// mov bx,word ptr ds:[eax+176]
// and ecx,FF
// mov word ptr ds:[eax+ecx*2+164],bx
// mov ecx,esi
// and ecx,FFFF
// mov byte ptr ds:[eax+174],dl
// mov cx,word ptr ds:[edi+ecx*2]
// mov word ptr ds:[eax+176],cx
// mov ecx,dword ptr ds:[eax+160]
// test ecx,eax.10000000
// je ff8_en.51D18C
// cmp byte ptr ds:[eax+23C],1
// jne ff8_en.51D18C
// mov ebx,dword ptr ds:[eax+1B4]
// or ecx,10000
// mov dword ptr ds:[eax+1C0],ebx
// mov ebx,dword ptr ds:[eax+1B8]
// mov dword ptr ds:[eax+1C4],ebx
// mov ebx,dword ptr ds:[eax+1BC]
// mov dword ptr ds:[eax+1C8],ebx
// mov bx,word ptr ds:[eax+21A]
// mov word ptr ds:[eax+21C],bx
// mov bx,word ptr ds:[eax+1FE]
// mov byte ptr ds:[eax+23C],0
// mov word ptr ds:[eax+202],bx
// mov dword ptr ds:[eax+160],ecx
// and esi,FFFF
// mov cx,word ptr ds:[edi+esi*2]
// mov edi,dword ptr ss:[esp+14]
// mov word ptr ss:[ebp],cx
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// cmp ecx,edx
// jge ff8_en.51D1C0
// mov al,byte ptr ss:[esp+18]
// sub al,2
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// pop ebp
// mov eax,3
// pop ebx
// ret 
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// ret 
// mov eax,dword ptr ss:[esp+14]
// pop edi
// pop esi
// pop ebp
// mov cl,byte ptr ds:[eax+184]
// pop ebx
// add cl,FE
// mov byte ptr ds:[eax+184],cl
// mov eax,3
// ret 
int SCRIPT_REQEW(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// push edi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ss:[esp+10]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+eax+C2]
// cmp al,FF
// je ff8_en.51D34D
// and eax,FF
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// mov si,word ptr ds:[ecx+eax*4+178]
// lea eax,dword ptr ds:[ecx+eax*4]
// mov ecx,edx
// add si,di
// and ecx,FF
// cmp word ptr ds:[eax+ecx*2+164],FFFF
// lea edi,dword ptr ds:[eax+ecx*2+164]
// jne ff8_en.51D34D
// xor ecx,ecx
// push ebx
// mov cl,byte ptr ds:[eax+174]
// mov bl,byte ptr ds:[eax+184]
// mov byte ptr ds:[ecx+eax+17C],bl
// mov cl,byte ptr ds:[eax+174]
// mov ebx,dword ptr ds:[1D9D0E4]
// cmp dl,cl
// jbe ff8_en.51D337
// push ebp
// mov bp,word ptr ds:[eax+176]
// and ecx,FF
// mov word ptr ds:[eax+ecx*2+164],bp
// mov byte ptr ds:[eax+174],dl
// mov edx,esi
// pop ebp
// and edx,FFFF
// mov cx,word ptr ds:[ebx+edx*2]
// mov word ptr ds:[eax+176],cx
// mov ecx,dword ptr ds:[eax+160]
// test ecx,eax.10000000
// je ff8_en.51D337
// cmp byte ptr ds:[eax+23C],1
// jne ff8_en.51D337
// mov edx,dword ptr ds:[eax+1B4]
// or ecx,10000
// mov dword ptr ds:[eax+1C0],edx
// mov edx,dword ptr ds:[eax+1B8]
// mov dword ptr ds:[eax+1C4],edx
// mov edx,dword ptr ds:[eax+1BC]
// mov dword ptr ds:[eax+1C8],edx
// mov dx,word ptr ds:[eax+21A]
// mov word ptr ds:[eax+21C],dx
// mov dx,word ptr ds:[eax+1FE]
// mov byte ptr ds:[eax+23C],0
// mov word ptr ds:[eax+202],dx
// mov dword ptr ds:[eax+160],ecx
// and esi,FFFF
// mov ax,word ptr ds:[ebx+esi*2]
// pop ebx
// mov word ptr ds:[edi],ax
// pop edi
// mov eax,3
// pop esi
// ret 
// pop edi
// mov eax,3
// pop esi
// ret 
int SCRIPT_PREQ(FieldEntity& entity, int arg) {
    return 0;
}



// push ecx
// push ebx
// push ebp
// mov ebp,dword ptr ss:[esp+10]
// mov edx,dword ptr ss:[esp+14]
// push esi
// push edi
// mov cl,byte ptr ss:[ebp+184]
// movsx eax,cl
// mov ebx,dword ptr ss:[ebp+eax*4-4]
// mov edi,dword ptr ss:[ebp+eax*4]
// lea eax,dword ptr ss:[ebp+eax*4]
// mov byte ptr ss:[esp+13],cl
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,byte ptr ds:[eax+edx+C2]
// cmp dl,FF
// je ff8_en.51D51A
// mov cl,byte ptr ss:[ebp+174]
// mov eax,1
// shl eax,cl
// mov cl,byte ptr ss:[ebp+175]
// test cl,al
// je ff8_en.51D4D5
// mov ecx,edx
// and ecx,FF
// mov eax,ecx
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// mov si,word ptr ds:[ecx+eax*4+178]
// lea eax,dword ptr ds:[ecx+eax*4]
// mov ecx,ebx
// add si,di
// and ecx,FF
// cmp word ptr ds:[eax+ecx*2+164],FFFF
// lea edi,dword ptr ds:[eax+ecx*2+164]
// jne ff8_en.51D4F8
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// mov ebp,ecx
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+ebp+17C],cl
// mov cl,byte ptr ds:[eax+174]
// cmp bl,cl
// jbe ff8_en.51D4BF
// mov bp,word ptr ds:[eax+176]
// and ecx,FF
// mov word ptr ds:[eax+ecx*2+164],bp
// mov ebp,dword ptr ds:[1D9D0E4]
// mov ecx,esi
// mov byte ptr ds:[eax+174],bl
// and ecx,FFFF
// mov cx,word ptr ss:[ebp+ecx*2]
// mov word ptr ds:[eax+176],cx
// mov ecx,dword ptr ds:[eax+160]
// test ecx,eax.10000000
// je ff8_en.51D4BF
// cmp byte ptr ds:[eax+23C],1
// jne ff8_en.51D4BF
// mov ebp,dword ptr ds:[eax+1B4]
// or ecx,10000
// mov dword ptr ds:[eax+1C0],ebp
// mov ebp,dword ptr ds:[eax+1B8]
// mov dword ptr ds:[eax+1C4],ebp
// mov ebp,dword ptr ds:[eax+1BC]
// mov dword ptr ds:[eax+1C8],ebp
// mov bp,word ptr ds:[eax+21A]
// mov word ptr ds:[eax+21C],bp
// mov bp,word ptr ds:[eax+1FE]
// mov byte ptr ds:[eax+23C],0
// mov word ptr ds:[eax+202],bp
// mov dword ptr ds:[eax+160],ecx
// mov eax,dword ptr ds:[1D9D0E4]
// mov ebp,dword ptr ss:[esp+18]
// and esi,FFFF
// mov cx,word ptr ds:[eax+esi*2]
// mov word ptr ds:[edi],cx
// and edx,FF
// mov ecx,dword ptr ds:[<entity_other>]
// mov eax,edx
// shl eax,4
// add eax,edx
// lea edx,dword ptr ds:[eax+eax*8]
// xor eax,eax
// mov al,byte ptr ds:[ecx+edx*4+174]
// cmp eax,ebx
// jne ff8_en.51D50F
// mov al,byte ptr ss:[esp+13]
// pop edi
// sub al,2
// pop esi
// mov byte ptr ss:[ebp+184],al
// pop ebp
// mov eax,3
// pop ebx
// pop ecx
// ret 
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// pop ecx
// ret 
// sub cl,2
// pop edi
// mov byte ptr ss:[ebp+184],cl
// pop esi
// pop ebp
// mov eax,3
// pop ebx
// pop ecx
// ret 
int SCRIPT_PREQSW(FieldEntity& entity, int arg) {
    return 0;
}



// push ecx
// push ebx
// push ebp
// mov ebp,dword ptr ss:[esp+10]
// mov edx,dword ptr ss:[esp+14]
// push esi
// push edi
// mov cl,byte ptr ss:[ebp+184]
// movsx eax,cl
// mov ebx,dword ptr ss:[ebp+eax*4-4]
// mov edi,dword ptr ss:[ebp+eax*4]
// lea eax,dword ptr ss:[ebp+eax*4]
// mov byte ptr ss:[esp+13],cl
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,byte ptr ds:[eax+edx+C2]
// cmp dl,FF
// je ff8_en.51D6EA
// mov cl,byte ptr ss:[ebp+174]
// mov eax,1
// shl eax,cl
// mov cl,byte ptr ss:[ebp+175]
// test cl,al
// je ff8_en.51D6A5
// mov ecx,edx
// and ecx,FF
// mov eax,ecx
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// mov si,word ptr ds:[ecx+eax*4+178]
// lea eax,dword ptr ds:[ecx+eax*4]
// mov ecx,ebx
// add si,di
// and ecx,FF
// cmp word ptr ds:[eax+ecx*2+164],FFFF
// lea edi,dword ptr ds:[eax+ecx*2+164]
// jne ff8_en.51D6C8
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+174]
// mov ebp,ecx
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+ebp+17C],cl
// mov cl,byte ptr ds:[eax+174]
// cmp bl,cl
// jbe ff8_en.51D68F
// mov bp,word ptr ds:[eax+176]
// and ecx,FF
// mov word ptr ds:[eax+ecx*2+164],bp
// mov ebp,dword ptr ds:[1D9D0E4]
// mov ecx,esi
// mov byte ptr ds:[eax+174],bl
// and ecx,FFFF
// mov cx,word ptr ss:[ebp+ecx*2]
// mov word ptr ds:[eax+176],cx
// mov ecx,dword ptr ds:[eax+160]
// test ecx,eax.10000000
// je ff8_en.51D68F
// cmp byte ptr ds:[eax+23C],1
// jne ff8_en.51D68F
// mov ebp,dword ptr ds:[eax+1B4]
// or ecx,10000
// mov dword ptr ds:[eax+1C0],ebp
// mov ebp,dword ptr ds:[eax+1B8]
// mov dword ptr ds:[eax+1C4],ebp
// mov ebp,dword ptr ds:[eax+1BC]
// mov dword ptr ds:[eax+1C8],ebp
// mov bp,word ptr ds:[eax+21A]
// mov word ptr ds:[eax+21C],bp
// mov bp,word ptr ds:[eax+1FE]
// mov byte ptr ds:[eax+23C],0
// mov word ptr ds:[eax+202],bp
// mov dword ptr ds:[eax+160],ecx
// mov eax,dword ptr ds:[1D9D0E4]
// mov ebp,dword ptr ss:[esp+18]
// and esi,FFFF
// mov cx,word ptr ds:[eax+esi*2]
// mov word ptr ds:[edi],cx
// and edx,FF
// mov ecx,dword ptr ds:[<entity_other>]
// mov eax,edx
// shl eax,4
// add eax,edx
// lea edx,dword ptr ds:[eax+eax*8]
// xor eax,eax
// mov al,byte ptr ds:[ecx+edx*4+174]
// cmp eax,ebx
// jge ff8_en.51D6DF
// mov al,byte ptr ss:[esp+13]
// pop edi
// sub al,2
// pop esi
// mov byte ptr ss:[ebp+184],al
// pop ebp
// mov eax,3
// pop ebx
// pop ecx
// ret 
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// pop ecx
// ret 
// sub cl,2
// pop edi
// mov byte ptr ss:[ebp+184],cl
// pop esi
// pop ebp
// mov eax,3
// pop ebx
// pop ecx
// ret 
int SCRIPT_PREQEW(FieldEntity& entity, int arg) {
    return 0;
}



int SCRIPT_DEBUG(FieldEntity& entity, int arg) {
    ff8vars.script_debug = true;
    return 3;
}



int SCRIPT_HALT(FieldEntity& entity, int arg) {
    return 1;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+194],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+190],edx
// mov edx,dword ptr ds:[1D9D0F0]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// push edx
// mov word ptr ds:[eax+1FA],cx
// call ff8_en.477890
// add esp,4
// mov eax,2
// ret 
int SCRIPT_SET(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+198],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+194],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+190],edx
// mov edx,dword ptr ds:[1D9D0F0]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// push edx
// mov word ptr ds:[eax+1FA],cx
// call ff8_en.477890
// add esp,4
// mov eax,2
// ret 
int SCRIPT_SET3(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+8]
// mov eax,ecx
// cdq 
// and edx,7
// add eax,edx
// sar eax,3
// and ecx,80000007
// lea eax,dword ptr ds:[eax+1CE4918]
// jns ff8_en.51D812
// dec ecx
// or ecx,FFFFFFF8
// inc ecx
// mov dl,1
// shl dl,cl
// mov cl,byte ptr ds:[eax]
// or cl,dl
// mov byte ptr ds:[eax],cl
// mov eax,2
// ret 
int SCRIPT_IDLOCK(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+8]
// mov eax,ecx
// cdq 
// and edx,7
// add eax,edx
// sar eax,3
// and ecx,80000007
// lea eax,dword ptr ds:[eax+1CE4918]
// jns ff8_en.51D852
// dec ecx
// or ecx,FFFFFFF8
// inc ecx
// mov dl,1
// shl dl,cl
// mov cl,byte ptr ds:[eax]
// not dl
// and cl,dl
// mov byte ptr ds:[eax],cl
// mov eax,2
// ret 
int SCRIPT_IDUNLOCK(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// movsx ecx,byte ptr ds:[eax+184]
// mov edx,dword ptr ds:[eax+ecx*4]
// lea ecx,dword ptr ds:[eax+ecx*4]
// dec edx
// mov dword ptr ds:[ecx],edx
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// cmp dword ptr ds:[eax+edx*4],0
// jne ff8_en.51D8A1
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov eax,3
// ret 
// mov eax,1
// ret 
int SCRIPT_WAIT(FieldEntity& entity, int arg) {
    return 0;
}



// push edi
// mov ecx,100
// xor eax,eax
// mov edi,ff8_en.1CFEAB8
// rep stosd dword ptr es:[edi],eax
// mov eax,2
// pop edi
// ret
int SCRIPT_CLEAR(FieldEntity& entity, int arg) {
    return 0;
}



// call ff8_en.52D210
// mov ecx,dword ptr ss:[esp+4]
// and eax,FF
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
int SCRIPT_RND(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov ax,word ptr ss:[esp+8]
// mov word ptr ds:[ecx+218],ax
// mov eax,2
// ret 
int SCRIPT_SETMODEL(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call <ff8_en.sub_52CC20>
// and eax,FF
// add esp,4
// lea ecx,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[eax+ecx*2]
// mov eax,2
// mov byte ptr ds:[edx*8+<SG_CHARACTER_ALTERNATE_MODEL>],bl
// pop ebx
// ret 
int SCRIPT_SETDRESS(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call <ff8_en.sub_52CC20>
// and eax,FF
// xor ecx,ecx
// add esp,4
// lea edx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edx*2]
// mov cl,byte ptr ds:[eax*8+<SG_CHARACTER_ALTERNATE_MODEL>]
// mov eax,2
// mov dword ptr ds:[esi+140],ecx
// pop esi
// ret 
int SCRIPT_GETDRESS(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ss:[esp+8]
// mov byte ptr ds:[eax+24F],cl
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+250],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+251],dl
// mov eax,2
// ret 
int SCRIPT_BASEANIME(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ss:[esp+8]
// mov byte ptr ds:[eax+252],cl
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+253],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+254],dl
// mov eax,2
// ret 
int SCRIPT_LADDERANIME(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[1CE48B0]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,esi
// dec al
// test edx,edx
// mov byte ptr ds:[ecx+184],al
// pop esi
// je ff8_en.51DA86
// mov dword ptr ds:[ecx+140],1
// mov eax,2
// ret 
// mov dword ptr ds:[ecx+140],0
// mov eax,2
// ret 
int SCRIPT_KEYSCAN(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[1CE48B8]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,esi
// dec al
// test edx,edx
// mov byte ptr ds:[ecx+184],al
// pop esi
// je ff8_en.51DAD6
// mov dword ptr ds:[ecx+140],1
// mov eax,2
// ret 
// mov dword ptr ds:[ecx+140],0
// mov eax,2
// ret 
int SCRIPT_KEYON(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[1CE48A0]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,esi
// dec al
// test edx,edx
// mov byte ptr ds:[ecx+184],al
// pop esi
// je ff8_en.51DB26
// mov dword ptr ds:[ecx+140],1
// mov eax,2
// ret 
// mov dword ptr ds:[ecx+140],0
// mov eax,2
// ret 
int SCRIPT_KEYSCAN2(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[1CE48A8]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,esi
// dec al
// test edx,edx
// mov byte ptr ds:[ecx+184],al
// pop esi
// je ff8_en.51DB76
// mov dword ptr ds:[ecx+140],1
// mov eax,2
// ret 
// mov dword ptr ds:[ecx+140],0
// mov eax,2
// ret 
int SCRIPT_KEYON2(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// or ecx,18
// mov dword ptr ds:[eax+68],ecx
// mov eax,ecx
// not eax
// shr eax,3
// and eax,1
// push eax
// call ff8_en.4B86C0
// add esp,4
// mov eax,2
// ret 
int SCRIPT_SALARYOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// and ecx,FFFFFFE7
// mov dword ptr ds:[eax+68],ecx
// mov eax,ecx
// not eax
// shr eax,3
// and eax,1
// push eax
// call ff8_en.4B86C0
// add esp,4
// mov eax,2
// ret 
int SCRIPT_SALARYON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// or ecx,10
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
int SCRIPT_SALARYDISOPOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// and ecx,FFFFFFEF
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
int SCRIPT_SALARYDISPON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+192],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+190],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+18E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+18C],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+18A],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,byte ptr ds:[<current_entity>]
// mov word ptr ds:[eax+188],dx
// mov byte ptr ds:[eax+194],1
// mov byte ptr ds:[eax+195],cl
// mov eax,2
// ret 
int SCRIPT_SETLINE(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+194],1
// mov eax,2
// ret 
int SCRIPT_LINEON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+194],0
// mov eax,2
// ret 
int SCRIPT_LINEOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+188],1
// mov eax,2
// ret 
int SCRIPT_DOORLINEON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+188],0
// mov eax,2
// ret 
int SCRIPT_DOORLINEOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// or ecx,2
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret 
int SCRIPT_USE(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFFFFFFD
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret
int SCRIPT_UNUSE(FieldEntity& entity, int arg) {
    return 0;
}



// mov cl,byte ptr ds:[1D9CEC9]
// xor al,al
// cmp cl,al
// jne ff8_en.51DDB1
// mov byte ptr ds:[1CE4903],al
// cmp byte ptr ds:[1D9D018],al
// jne ff8_en.51DDBF
// mov eax,2
// ret 
// push esi
// mov esi,dword ptr ds:[<entity_other>]
// push edi
// mov edi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[1D9D018],al
// mov byte ptr ds:[1CE4775],al
// mov dl,byte ptr ds:[edi+C2]
// cmp dl,FF
// je ff8_en.51DE10
// mov ecx,edx
// and ecx,FF
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea eax,dword ptr ds:[eax+eax*8]
// lea ecx,dword ptr ds:[esi+eax*4+160]
// mov eax,dword ptr ds:[esi+eax*4+160]
// test al,40
// jne ff8_en.51DE10
// or al,4
// mov byte ptr ds:[1CE4772],dl
// mov dword ptr ds:[ecx],eax
// mov dl,byte ptr ds:[edi+C3]
// cmp dl,FF
// je ff8_en.51DE49
// mov ecx,edx
// and ecx,FF
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea ecx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[esi+ecx*4+160]
// test al,40
// lea ecx,dword ptr ds:[esi+ecx*4+160]
// jne ff8_en.51DE49
// or al,4
// mov byte ptr ds:[1CE4773],dl
// mov dword ptr ds:[ecx],eax
// mov dl,byte ptr ds:[edi+C4]
// cmp dl,FF
// je ff8_en.51DE82
// mov ecx,edx
// and ecx,FF
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea eax,dword ptr ds:[eax+eax*8]
// lea ecx,dword ptr ds:[esi+eax*4+160]
// mov eax,dword ptr ds:[esi+eax*4+160]
// test al,40
// jne ff8_en.51DE82
// or al,4
// mov byte ptr ds:[1CE4774],dl
// mov dword ptr ds:[ecx],eax
// pop edi
// mov eax,2
// pop esi
// ret 
int SCRIPT_UCON(FieldEntity& entity, int arg) {
    return 0;
}



// mov cl,byte ptr ds:[1D9D018]
// push ebx
// xor ebx,ebx
// mov al,1
// cmp cl,bl
// mov byte ptr ds:[1CE4903],al
// je ff8_en.51DEAB
// mov eax,2
// pop ebx
// ret 
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// push esi
// push edi
// mov byte ptr ds:[1D9D018],al
// mov cl,byte ptr ds:[edx+C2]
// mov byte ptr ds:[1CE4775],al
// cmp cl,FF
// je ff8_en.51DF5D
// and ecx,FF
// mov esi,dword ptr ds:[<entity_other>]
// mov eax,ecx
// xor edx,edx
// shl eax,4
// add eax,ecx
// push ebx
// lea eax,dword ptr ds:[eax+eax*8]
// mov dl,byte ptr ds:[esi+eax*4+24F]
// push edx
// push D
// push ecx
// call ff8_en.532890
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor eax,eax
// mov edi,dword ptr ds:[<entity_other>]
// add esp,10
// mov al,byte ptr ds:[edx+C2]
// mov esi,eax
// shl eax,4
// add eax,esi
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edi+ecx*4]
// mov cl,byte ptr ds:[edi+ecx*4+24F]
// mov byte ptr ds:[eax+24E],cl
// mov ecx,dword ptr ds:[esi*4+1DCB340]
// mov word ptr ds:[eax+206],bx
// mov word ptr ds:[eax+20A],bx
// mov cx,word ptr ds:[ecx+C]
// mov word ptr ds:[eax+20C],cx
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFFF27FB
// or ch,20
// mov dword ptr ds:[eax+160],ecx
// jmp ff8_en.51DF63
// mov edi,dword ptr ds:[<entity_other>]
// cmp byte ptr ds:[1CE4773],FF
// je ff8_en.51E004
// xor ecx,ecx
// push ebx
// mov cl,byte ptr ds:[edx+C3]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea edx,dword ptr ds:[eax+eax*8]
// xor eax,eax
// mov al,byte ptr ds:[edi+edx*4+24F]
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor ecx,ecx
// mov edi,dword ptr ds:[<entity_other>]
// add esp,10
// mov cl,byte ptr ds:[edx+C3]
// mov byte ptr ds:[1CE4773],FF
// mov esi,ecx
// mov eax,esi
// shl eax,4
// add eax,esi
// lea eax,dword ptr ds:[eax+eax*8]
// mov cl,byte ptr ds:[edi+eax*4+24F]
// lea eax,dword ptr ds:[edi+eax*4]
// mov byte ptr ds:[eax+24E],cl
// mov ecx,dword ptr ds:[esi*4+1DCB340]
// mov word ptr ds:[eax+206],bx
// mov word ptr ds:[eax+20A],bx
// mov cx,word ptr ds:[ecx+C]
// mov word ptr ds:[eax+20C],cx
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFFF27FB
// or ch,20
// mov dword ptr ds:[eax+160],ecx
// cmp byte ptr ds:[1CE4774],FF
// je ff8_en.51E0A2
// xor ecx,ecx
// push ebx
// mov cl,byte ptr ds:[edx+C4]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea edx,dword ptr ds:[eax+eax*8]
// xor eax,eax
// mov al,byte ptr ds:[edi+edx*4+24F]
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor ecx,ecx
// add esp,10
// mov byte ptr ds:[1CE4774],FF
// mov cl,byte ptr ds:[edx+C4]
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[ecx*4+1DCB340]
// lea eax,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+eax*4]
// mov dl,byte ptr ds:[eax+24F]
// mov byte ptr ds:[eax+24E],dl
// mov dx,word ptr ds:[ecx+C]
// mov word ptr ds:[eax+206],bx
// mov word ptr ds:[eax+20A],bx
// mov word ptr ds:[eax+20C],dx
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFFF27FB
// or ch,20
// mov dword ptr ds:[eax+160],ecx
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_UCOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov byte ptr ds:[1CE4775],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// test edx,edx
// jne ff8_en.51E0DA
// mov byte ptr ds:[1CE4775],1
// mov eax,2
// ret 
int SCRIPT_KEY(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push esi
// mov cl,byte ptr ds:[eax+184]
// mov esi,dword ptr ds:[eax+160]
// movsx edx,cl
// or esi,80
// dec cl
// mov dword ptr ds:[eax+160],esi
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,dl
// cmp cl,3
// mov byte ptr ds:[eax+255],dl
// jb ff8_en.51E12E
// cmp cl,5
// jbe ff8_en.51E122
// cmp cl,7
// jne ff8_en.51E12E
// or esi,4000000
// mov dword ptr ds:[eax+160],esi
// mov dl,byte ptr ds:[<SG_PARTY_FIELD1>]
// pop esi
// cmp dl,cl
// je ff8_en.51E150
// cmp byte ptr ds:[<SG_PARTY_FIELD2>],cl
// je ff8_en.51E150
// cmp byte ptr ds:[<SG_PARTY_FIELD3>],cl
// je ff8_en.51E150
// and dword ptr ds:[eax+160],FFFFFFFD
// mov eax,2
// ret 
int SCRIPT_SETPC(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push ebx
// push <ff8_en.aFunc_addpartyD>
// call <ff8_en._printf>
// push ebx
// call <ff8_en.sub_52CBE0>
// add esp,C
// cmp al,FF
// jne ff8_en.51E25A
// push FF
// call <ff8_en.sub_52CBE0>
// and eax,FF
// add esp,4
// cmp eax,FF
// je ff8_en.51E1ED
// push esi
// push FF
// mov byte ptr ds:[eax+<SG_PARTY_FIELD1>],bl
// call <ff8_en.sub_52CC00>
// and eax,FF
// push ebx
// mov esi,eax
// call <ff8_en.sub_52CC20>
// add esp,8
// mov byte ptr ds:[esi+<SG_PARTY_BATTLE1>],al
// cmp esi,FF
// pop esi
// jne ff8_en.51E1ED
// push 38F
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// cmp ebx,8
// jl ff8_en.51E210
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// lea ecx,dword ptr ds:[ebx-8]
// mov edx,1
// pop ebx
// shl edx,cl
// mov ecx,dword ptr ds:[eax+68]
// or ecx,edx
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
// lea eax,dword ptr ds:[ebx+ebx*8]
// lea eax,dword ptr ds:[ebx+eax*2]
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],1
// mov cx,word ptr ds:[eax*8+<SG_CHARACTER_EXISTS>]
// test ebx,ebx
// jne ff8_en.51E248
// or ecx,4
// mov word ptr ds:[<SG_CHARACTER_EXISTS>],cx
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],8
// call <ff8_en.sub_495EF0>
// mov eax,2
// pop ebx
// ret 
// cmp ebx,4
// je ff8_en.51E255
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],8
// call <ff8_en.sub_495EF0>
// mov eax,2
// pop ebx
// ret 
int SCRIPT_ADDPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// push <ff8_en.aFunc_subpartyD>
// call <ff8_en._printf>
// push esi
// call <ff8_en.sub_52CBE0>
// and eax,FF
// add esp,C
// cmp eax,FF
// je ff8_en.51E2B0
// mov byte ptr ds:[eax+<SG_PARTY_FIELD1>],FF
// push esi
// call ff8_en.52CC50
// and eax,FF
// add esp,4
// mov esi,eax
// cmp esi,FF
// je ff8_en.51E2E9
// test byte ptr ds:[<SG_ODIN_ANGEL_FLAG>],1
// je ff8_en.51E2E2
// xor eax,eax
// mov al,byte ptr ds:[esi+<SG_PARTY_BATTLE1>]
// push eax
// call <ff8_en.sub_4ACE50>
// add esp,4
// mov byte ptr ds:[esi+<SG_PARTY_BATTLE1>],FF
// call <ff8_en.sub_495EF0>
// xor ecx,ecx
// mov edx,FFFE
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// cmp al,FF
// je ff8_en.51E335
// and eax,FF
// lea esi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+esi*2]
// cmp word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],0
// jne ff8_en.51E335
// mov word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],1
// xor eax,eax
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// lea esi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+esi*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_STATUS>],dx
// inc ecx
// cmp ecx,3
// jl ff8_en.51E2F5
// mov eax,2
// pop esi
// ret 
int SCRIPT_SUBPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// push ebx
// push <ff8_en.aFunc_changepar>
// call <ff8_en._printf>
// push ebx
// call <ff8_en.sub_52CBE0>
// add esp,10
// cmp al,FF
// jne ff8_en.51E3EA
// mov al,byte ptr ds:[esi+<SG_PARTY_FIELD1>]
// push edi
// push eax
// call ff8_en.52CC50
// and eax,FF
// add esp,4
// mov edi,eax
// cmp edi,FF
// jne ff8_en.51E3C7
// push eax
// call <ff8_en.sub_52CC00>
// and eax,edi
// add esp,4
// mov edi,eax
// cmp edi,FF
// jne ff8_en.51E3C7
// mov edi,esi
// push ebx
// call <ff8_en.sub_52CC20>
// add esp,4
// mov byte ptr ds:[edi+<SG_PARTY_BATTLE1>],al
// mov byte ptr ds:[esi+<SG_PARTY_FIELD1>],bl
// call <ff8_en.sub_495EF0>
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_CHANGEPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// push ecx
// mov eax,dword ptr ss:[esp+8]
// push ebx
// push esi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+8],edx
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov al,byte ptr ds:[<SG_ODIN_ANGEL_FLAG>]
// mov dword ptr ss:[esp+10],edx
// test al,1
// je ff8_en.51E4FE
// cmp edx,FF
// jne ff8_en.51E471
// mov al,byte ptr ds:[<SG_PARTY_FIELD1>]
// push eax
// call <ff8_en.sub_52CC20>
// and eax,FF
// push eax
// call <ff8_en.sub_4ACE50>
// mov edx,dword ptr ss:[esp+18]
// add esp,8
// cmp dword ptr ss:[esp+8],FF
// jne ff8_en.51E499
// mov cl,byte ptr ds:[<SG_PARTY_FIELD2>]
// push ecx
// call <ff8_en.sub_52CC20>
// and eax,FF
// push eax
// call <ff8_en.sub_4ACE50>
// mov edx,dword ptr ss:[esp+18]
// add esp,8
// cmp ebx,FF
// jne ff8_en.51E4BC
// mov dl,byte ptr ds:[<SG_PARTY_FIELD3>]
// push edx
// call <ff8_en.sub_52CC20>
// and eax,ebx
// push eax
// call <ff8_en.sub_4ACE50>
// mov edx,dword ptr ss:[esp+18]
// add esp,8
// mov al,byte ptr ss:[esp+8]
// push ebx
// mov byte ptr ds:[<SG_PARTY_FIELD1>],dl
// mov byte ptr ds:[<SG_PARTY_FIELD2>],al
// mov byte ptr ds:[<SG_PARTY_FIELD3>],bl
// call <ff8_en.sub_52CC20>
// mov cl,byte ptr ds:[<SG_PARTY_FIELD1>]
// mov byte ptr ds:[<SG_PARTY_BATTLE3>],al
// push ecx
// call <ff8_en.sub_52CC20>
// mov dl,byte ptr ds:[<SG_PARTY_FIELD2>]
// mov byte ptr ds:[<SG_PARTY_BATTLE2>],al
// push edx
// call <ff8_en.sub_52CC20>
// add esp,C
// jmp ff8_en.51E51F
// mov al,byte ptr ss:[esp+8]
// mov byte ptr ds:[<SG_PARTY_FIELD1>],dl
// mov byte ptr ds:[<SG_PARTY_FIELD2>],al
// mov byte ptr ds:[<SG_PARTY_FIELD3>],bl
// mov byte ptr ds:[<SG_PARTY_BATTLE3>],bl
// mov byte ptr ds:[<SG_PARTY_BATTLE2>],dl
// mov byte ptr ds:[<SG_PARTY_BATTLE1>],al
// mov edx,dword ptr ds:[<SG_PARTY_BATTLE1>]
// xor eax,eax
// xor ecx,ecx
// mov al,byte ptr ds:[<SG_PARTY_BATTLE3>]
// mov cl,byte ptr ds:[<SG_PARTY_BATTLE2>]
// push eax
// and edx,FF
// push ecx
// xor eax,eax
// mov al,byte ptr ds:[<SG_PARTY_FIELD3>]
// push edx
// mov edx,dword ptr ds:[<SG_PARTY_FIELD1>]
// xor ecx,ecx
// mov cl,byte ptr ds:[<SG_PARTY_FIELD2>]
// push eax
// and edx,FF
// push ecx
// push edx
// push <ff8_en.aFunc_setpartyF>
// call <ff8_en._printf>
// add esp,1C
// call <ff8_en.sub_495EF0>
// xor ecx,ecx
// mov edx,FFFE
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// cmp al,FF
// je ff8_en.51E5B9
// and eax,FF
// lea esi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+esi*2]
// cmp word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],0
// jne ff8_en.51E5B9
// mov word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],1
// xor eax,eax
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// lea esi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+esi*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_STATUS>],dx
// inc ecx
// cmp ecx,3
// jl ff8_en.51E579
// pop esi
// mov eax,2
// pop ebx
// pop ecx
// ret 
int SCRIPT_SETPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// call ff8_en.52D050
// mov eax,2
// ret 
int SCRIPT_REFRESHPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// push edi
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov edi,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push edi
// call <ff8_en.sub_52CBE0>
// and eax,FF
// add esp,4
// cmp eax,FF
// mov dword ptr ds:[esi+140],eax
// jne ff8_en.51E61F
// mov dword ptr ds:[esi+140],FFFFFFFF
// mov edx,dword ptr ds:[esi+140]
// push edi
// push edx
// push <ff8_en.aDFunc_ispartyD>
// call <ff8_en._printf>
// add esp,C
// mov eax,2
// pop edi
// pop esi
// ret 
int SCRIPT_ISPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// xor eax,eax
// mov al,byte ptr ds:[edx+<SG_PARTY_FIELD1>]
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
int SCRIPT_GETPARTY(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[edx+184]
// movsx eax,cl
// dec cl
// mov eax,dword ptr ds:[edx+eax*4]
// mov byte ptr ds:[edx+184],cl
// cmp eax,A
// ja ff8_en.51E6DB
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+51E700]
// jmp dword ptr ds:[ecx*4+51E6F0]
// or byte ptr ds:[<SG_CHARACTER_EXISTS>],D
// mov eax,2
// ret 
// lea edx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edx*2]
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],1
// mov eax,2
// ret 
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// lea ecx,dword ptr ds:[eax-8]
// mov eax,1
// shl eax,cl
// mov ecx,dword ptr ds:[edx+68]
// or ecx,eax
// mov eax,2
// mov dword ptr ds:[edx+68],ecx
// ret 
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+ecx*2]
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],9
// mov eax,2
// ret 
int SCRIPT_ADDMEMBER(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// call <ff8_en.sub_52CC20>
// and eax,FF
// push eax
// call <ff8_en.sub_4ACE50>
// lea eax,dword ptr ds:[esi-6]
// add esp,8
// cmp eax,4
// ja ff8_en.51E7A4
// jmp dword ptr ds:[eax*4+51E7BC]
// lea eax,dword ptr ds:[esi+esi*8]
// lea eax,dword ptr ds:[esi+eax*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],FFF6
// call ff8_en.56DB20
// mov eax,2
// pop esi
// ret 
// lea ecx,dword ptr ds:[esi+esi*8]
// lea eax,dword ptr ds:[esi+ecx*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],FFF6
// call ff8_en.56DB50
// mov eax,2
// pop esi
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// lea ecx,dword ptr ds:[esi-8]
// mov edx,1
// pop esi
// shl edx,cl
// mov ecx,dword ptr ds:[eax+68]
// not edx
// and ecx,edx
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
// lea eax,dword ptr ds:[esi+esi*8]
// lea eax,dword ptr ds:[esi+eax*2]
// pop esi
// and word ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],FFF6
// mov eax,2
// ret 
int SCRIPT_SUBMEMBER(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// cmp ecx,8
// jl ff8_en.51E80F
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add ecx,FFFFFFF8
// mov edx,1
// shl edx,cl
// mov ecx,dword ptr ds:[eax+68]
// mov eax,2
// and edx,ecx
// mov dword ptr ds:[esi+140],edx
// pop esi
// ret 
// push ecx
// call <ff8_en.sub_52CC20>
// and eax,FF
// add esp,4
// cmp eax,FF
// jne ff8_en.51E835
// mov dword ptr ds:[esi+140],0
// mov eax,2
// pop esi
// ret 
// lea ecx,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[eax+ecx*2]
// mov al,byte ptr ds:[edx*8+<SG_CHARACTER_EXISTS>]
// and eax,1
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_ISMEMBER(FieldEntity& entity, int arg) {
    return 0;
}



// push ebx
// push esi
// xor esi,esi
// xor ebx,ebx
// push ebx
// call <ff8_en.sub_52CBE0>
// add esp,4
// cmp al,FF
// jne ff8_en.51E887
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// inc esi
// mov byte ptr ds:[eax+esi+BB],bl
// mov byte ptr ds:[eax+esi+BE],bl
// inc ebx
// cmp ebx,6
// jl ff8_en.51E866
// call <ff8_en.sub_495EF0>
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_SETPARTY2(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// sub esp,8
// xor eax,eax
// mov dl,byte ptr ds:[eax+<SG_PARTY_FIELD1>]
// mov byte ptr ss:[esp+eax],dl
// mov dl,byte ptr ds:[eax+<SG_PARTY_BATTLE1>]
// mov byte ptr ss:[esp+eax+4],dl
// mov dl,byte ptr ds:[ecx+eax+BC]
// mov byte ptr ds:[eax+<SG_PARTY_FIELD1>],dl
// mov dl,byte ptr ds:[ecx+eax+BF]
// mov byte ptr ds:[eax+<SG_PARTY_BATTLE1>],dl
// mov dl,byte ptr ss:[esp+eax]
// mov byte ptr ds:[ecx+eax+BC],dl
// mov dl,byte ptr ss:[esp+eax+4]
// mov byte ptr ds:[ecx+eax+BF],dl
// inc eax
// cmp eax,3
// jl ff8_en.51E8AB
// call <ff8_en.sub_495EF0>
// mov eax,2
// add esp,8
// ret 
int SCRIPT_SWAP(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov eax,dword ptr ds:[ecx+68]
// or ah,8
// mov dword ptr ds:[ecx+68],eax
// mov al,byte ptr ds:[edx+184]
// movsx esi,al
// dec al
// mov esi,dword ptr ds:[edx+esi*4]
// mov byte ptr ds:[edx+184],al
// test esi,esi
// je ff8_en.51E944
// mov byte ptr ds:[ecx+F3],FF
// mov al,byte ptr ds:[ecx+F3]
// xor esi,esi
// mov byte ptr ds:[1CFF6E8],al
// mov byte ptr ds:[1CFE73F],al
// xor ebx,ebx
// push ebx
// call <ff8_en.sub_52CBE0>
// add esp,4
// cmp al,FF
// jne ff8_en.51E979
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// inc esi
// mov byte ptr ds:[eax+esi+BB],bl
// mov byte ptr ds:[eax+esi+BE],bl
// inc ebx
// cmp ebx,6
// jl ff8_en.51E958
// call <ff8_en.sub_495EF0>
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_LASTIN(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// and ch,F7
// mov dword ptr ds:[eax+68],ecx
// xor al,al
// mov byte ptr ds:[1CFF6E8],al
// mov byte ptr ds:[1CFE73F],al
// call <ff8_en.sub_495EF0>
// mov eax,2
// ret 
int SCRIPT_LASTOUT(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// not ecx
// mov dl,byte ptr ds:[eax+F3]
// and dl,cl
// mov byte ptr ds:[eax+F3],dl
// mov al,dl
// mov byte ptr ds:[1CFF6E8],al
// mov byte ptr ds:[1CFE73F],al
// call <ff8_en.sub_495EF0>
// mov eax,2
// ret 
int SCRIPT_SEALEDOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call <ff8_en.sub_52CC20>
// and eax,FF
// push eax
// call <ff8_en.sub_4ACE50>
// add esp,8
// mov eax,2
// ret 
int SCRIPT_RESETGF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push esi
// mov cl,byte ptr ds:[eax+184]
// dec cl
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// dec cl
// mov esi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// cmp edx,8
// jl ff8_en.51EA9C
// push edx
// call <ff8_en.sub_52CC20>
// and eax,FF
// add esp,4
// mov edx,eax
// cmp edx,FF
// je ff8_en.51EAC5
// test esi,esi
// je ff8_en.51EAB5
// lea eax,dword ptr ds:[edx+edx*8]
// pop esi
// lea eax,dword ptr ds:[edx+eax*2]
// or byte ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],6
// mov eax,2
// ret 
// lea ecx,dword ptr ds:[edx+edx*8]
// lea eax,dword ptr ds:[edx+ecx*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_EXISTS>],FFF9
// mov eax,2
// pop esi
// ret 
int SCRIPT_HOLD(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// mov bl,byte ptr ds:[1D9CDDC]
// xor dl,dl
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFFFFFF7
// test bl,2
// mov dword ptr ds:[eax+160],ecx
// jne ff8_en.51EB05
// xor ebx,ebx
// push esi
// mov bl,byte ptr ds:[eax+256]
// mov esi,dword ptr ds:[ebx*4+1DCB340]
// mov byte ptr ds:[esi+60],dl
// pop esi
// test cl,10
// pop ebx
// je ff8_en.51EB24
// mov byte ptr ds:[eax+24C],1
// mov byte ptr ds:[eax+249],dl
// mov byte ptr ds:[eax+24B],dl
// mov eax,2
// ret 
// mov byte ptr ds:[eax+24C],dl
// mov byte ptr ds:[eax+249],dl
// mov byte ptr ds:[eax+24B],dl
// mov eax,2
// ret 
int SCRIPT_SHOW(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// mov bl,byte ptr ds:[1D9CDDC]
// mov dl,1
// mov ecx,dword ptr ds:[eax+160]
// or ecx,8
// test bl,2
// mov dword ptr ds:[eax+160],ecx
// jne ff8_en.51EB75
// xor ebx,ebx
// push esi
// mov bl,byte ptr ds:[eax+256]
// mov esi,dword ptr ds:[ebx*4+1DCB340]
// mov byte ptr ds:[esi+60],dl
// pop esi
// mov bl,byte ptr ds:[eax+24C]
// test bl,bl
// pop ebx
// je ff8_en.51EB85
// or ecx,10
// jmp ff8_en.51EB88
// and ecx,FFFFFFEF
// mov dword ptr ds:[eax+160],ecx
// mov byte ptr ds:[eax+24C],dl
// mov byte ptr ds:[eax+249],dl
// mov byte ptr ds:[eax+24B],dl
// mov eax,2
// ret 
int SCRIPT_HIDE(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+24B],0
// mov eax,2
// ret 
int SCRIPT_TALKON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+24B],1
// mov eax,2
// ret 
int SCRIPT_TALKOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+249],0
// mov eax,2
// ret 
int SCRIPT_PUSHON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+249],1
// mov eax,2
// ret 
int SCRIPT_PUSHOFF(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// push edi
// xor edi,edi
// mov al,byte ptr ds:[esi+255]
// cmp byte ptr ds:[edi+<SG_PARTY_FIELD1>],al
// je ff8_en.51EC54
// inc edi
// cmp edi,3
// jl ff8_en.51EC3E
// pop edi
// mov eax,2
// pop esi
// ret 
// mov ecx,dword ptr ds:[esi+160]
// push ebx
// movzx bx,byte ptr ds:[esi+24F]
// and ecx,FFFFFFFB
// push 0
// movsx eax,bx
// mov dword ptr ds:[esi+160],ecx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov byte ptr ds:[edi+1CE4772],FF
// pop ebx
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov word ptr ds:[esi+206],0
// mov cx,word ptr ds:[eax+C]
// or edx,2040
// mov word ptr ds:[esi+20A],0
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],0
// mov dword ptr ds:[esi+160],edx
// pop edi
// mov eax,2
// pop esi
// ret 
int SCRIPT_FOLLOWOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// mov dl,byte ptr ds:[ecx+255]
// cmp byte ptr ds:[eax+<SG_PARTY_FIELD1>],dl
// je ff8_en.51ED10
// inc eax
// cmp eax,3
// jl ff8_en.51ECFC
// mov eax,2
// ret 
// mov edx,dword ptr ds:[ecx+160]
// and edx,FFFFFFBF
// mov dword ptr ds:[ecx+160],edx
// mov cl,byte ptr ds:[ecx+256]
// mov byte ptr ds:[eax+1CE4772],cl
// mov eax,2
// ret 
int SCRIPT_FOLLOWON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+24C],1
// mov eax,2
// ret 
int SCRIPT_THROUGHON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[eax+24C],0
// mov eax,2
// ret 
int SCRIPT_THROUGHOFF(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// mov eax,dword ptr ds:[ecx*4+1D9D020]
// test eax,eax
// jne ff8_en.51EDB1
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// push eax
// push esi
// call ff8_en.47B460
// add esp,8
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_ISTOUCH(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[ecx+1F8],dx
// mov eax,2
// ret 
int SCRIPT_TALKRADIUS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[ecx+1F6],dx
// mov eax,2
// ret 
int SCRIPT_PUSHRADIUS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov eax,dword ptr ds:[ecx+190]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov dword ptr ds:[ecx+140],eax
// mov eax,dword ptr ds:[ecx+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov dword ptr ds:[ecx+144],eax
// mov eax,dword ptr ds:[ecx+198]
// cdq 
// and edx,FFF
// add eax,edx
// xor edx,edx
// sar eax,C
// mov dword ptr ds:[ecx+148],eax
// xor eax,eax
// mov al,byte ptr ds:[ecx+241]
// mov dx,word ptr ds:[ecx+1FA]
// mov dword ptr ds:[ecx+150],eax
// mov dword ptr ds:[ecx+154],edx
// movsx eax,word ptr ds:[ecx+1FE]
// mov dword ptr ds:[ecx+158],eax
// mov eax,2
// ret 
int SCRIPT_GETINFO(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// xor ebx,ebx
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov bl,byte ptr ds:[edx+esi+C2]
// mov edx,ebx
// mov eax,edx
// shl eax,4
// add eax,edx
// mov edx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea esi,dword ptr ds:[edx+eax*4]
// mov eax,dword ptr ds:[edx+eax*4+190]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov dword ptr ds:[ecx+140],eax
// mov eax,dword ptr ds:[esi+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov dword ptr ds:[ecx+144],eax
// mov eax,dword ptr ds:[esi+198]
// cdq 
// and edx,FFF
// add eax,edx
// xor edx,edx
// sar eax,C
// mov dword ptr ds:[ecx+148],eax
// xor eax,eax
// mov al,byte ptr ds:[esi+241]
// mov dx,word ptr ds:[esi+1FA]
// mov dword ptr ds:[ecx+150],eax
// mov dword ptr ds:[ecx+154],edx
// movsx eax,word ptr ds:[esi+1FE]
// mov dword ptr ds:[ecx+158],eax
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_PGETINFO(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call <ff8_en.sub_52CC20>
// add esp,4
// and eax,FF
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_WHOAMI(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov esi,ebx
// and esi,1
// push esi
// call ff8_en.4ACAE0
// add esp,4
// test esi,esi
// je ff8_en.51F075
// push ebp
// mov ebp,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,ff8_en.1CFE8D4
// mov esi,ff8_en.1CFE690
// mov edi,FFFFFF44
// sub ecx,ebp
// sub esi,ebp
// lea eax,dword ptr ss:[ebp+BC]
// sub edi,ebp
// mov dl,byte ptr ds:[ecx+eax]
// mov byte ptr ds:[eax],dl
// mov dl,byte ptr ds:[esi+eax]
// mov byte ptr ds:[eax+3],dl
// inc eax
// lea edx,dword ptr ds:[edi+eax]
// cmp edx,3
// jl ff8_en.51F003
// test bl,2
// je ff8_en.51F038
// mov al,byte ptr ss:[ebp+68]
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// and al,7
// mov word ptr ds:[<MenuState>],16
// mov byte ptr ds:[1CE490B],al
// jmp ff8_en.51F047
// mov ecx,dword ptr ss:[ebp+68]
// and ecx,7
// push ecx
// call ff8_en.4ACF50
// add esp,4
// xor edi,edi
// mov esi,<ff8_en.SG_CHARACTER_MODEL_ID>
// pop ebp
// cmp byte ptr ds:[esi],8
// jae ff8_en.51F05D
// push edi
// call <ff8_en.sub_4ACE50>
// add esp,4
// add esi,98
// inc edi
// cmp esi,ff8_en.1CFE5B0
// jl ff8_en.51F04F
// pop edi
// pop esi
// mov eax,3
// pop ebx
// ret 
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,ff8_en.1CFE8D1
// mov esi,ff8_en.1CFE68D
// mov edi,FFFFFF41
// sub edx,ecx
// sub esi,ecx
// lea eax,dword ptr ds:[ecx+BF]
// sub edi,ecx
// mov cl,byte ptr ds:[eax-3]
// mov byte ptr ds:[edx+eax],cl
// mov cl,byte ptr ds:[eax]
// mov byte ptr ds:[esi+eax],cl
// inc eax
// lea ecx,dword ptr ds:[edi+eax]
// cmp ecx,3
// jl ff8_en.51F096
// pop edi
// pop esi
// mov eax,3
// pop ebx
// ret 
int SCRIPT_JUNCTION(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[edx*4+1D9D020]
// mov edx,dword ptr ds:[ecx+190]
// mov dword ptr ds:[eax+190],edx
// mov edx,dword ptr ds:[ecx+194]
// mov dword ptr ds:[eax+194],edx
// mov edx,dword ptr ds:[ecx+198]
// mov dword ptr ds:[eax+198],edx
// mov dl,byte ptr ds:[ecx+241]
// mov byte ptr ds:[eax+241],dl
// mov dx,word ptr ds:[ecx+1FA]
// mov cx,word ptr ds:[ecx+1FE]
// mov word ptr ds:[eax+1FA],dx
// mov edx,dword ptr ds:[1D9D0F0]
// mov word ptr ds:[eax+1FE],cx
// push edx
// call ff8_en.477890
// add esp,4
// mov eax,2
// ret 
int SCRIPT_COPYINFO(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[eax+184]
// xor ebx,ebx
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov bl,byte ptr ds:[edx+esi+C2]
// mov edx,ebx
// mov ecx,edx
// shl ecx,4
// add ecx,edx
// mov edx,dword ptr ds:[<entity_other>]
// lea ecx,dword ptr ds:[ecx+ecx*8]
// lea ecx,dword ptr ds:[edx+ecx*4]
// mov edx,dword ptr ds:[ecx+190]
// mov dword ptr ds:[eax+190],edx
// mov edx,dword ptr ds:[ecx+194]
// mov dword ptr ds:[eax+194],edx
// mov edx,dword ptr ds:[ecx+198]
// mov dword ptr ds:[eax+198],edx
// mov dl,byte ptr ds:[ecx+241]
// mov byte ptr ds:[eax+241],dl
// mov dx,word ptr ds:[ecx+1FA]
// mov cx,word ptr ds:[ecx+1FE]
// mov word ptr ds:[eax+1FA],dx
// mov edx,dword ptr ds:[1D9D0F0]
// mov word ptr ds:[eax+1FE],cx
// push edx
// call ff8_en.477890
// add esp,4
// mov eax,2
// pop esi
// pop ebx
// ret 
int SCRIPT_PCOPYINFO(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// cmp edx,3
// ja ff8_en.51F288
// jmp dword ptr ds:[edx*4+51F2AC]
// mov ecx,dword ptr ds:[eax+160]
// mov dword ptr ss:[esp+4],1
// or ecx,ff8_en.2000000
// mov dword ptr ds:[eax+160],ecx
// mov ecx,F
// jmp ff8_en.51F28C
// mov ecx,dword ptr ds:[eax+160]
// mov dword ptr ss:[esp+4],0
// and ecx,FDFFFFFF
// mov dword ptr ds:[eax+160],ecx
// mov ecx,F
// jmp ff8_en.51F28C
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FEFFFFFF
// mov dword ptr ds:[eax+160],ecx
// mov ecx,22
// jmp ff8_en.51F28C
// mov ecx,dword ptr ds:[eax+160]
// or ecx,ff8_en.1000000
// mov dword ptr ds:[eax+160],ecx
// mov ecx,21
// jmp ff8_en.51F28C
// mov ecx,dword ptr ss:[esp+4]
// mov edx,dword ptr ss:[esp+4]
// push 0
// push edx
// push ecx
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+256]
// push ecx
// call ff8_en.532340
// add esp,10
// mov eax,2
// ret 
int SCRIPT_ACTORMODE(FieldEntity& entity, int arg) {
    return 0;
}



// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// push edi
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// mov ebx,dword ptr ds:[esi+ecx*4-4]
// lea ecx,dword ptr ds:[esi+ecx*4]
// inc ebx
// mov ecx,dword ptr ds:[ecx]
// sub ecx,0
// je ff8_en.51F2F0
// dec ecx
// je ff8_en.51F2E9
// mov edi,6
// jmp ff8_en.51F2F5
// mov edi,A
// jmp ff8_en.51F2F5
// mov edi,8
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[edx+68]
// test ch,1
// je ff8_en.51F314
// sub al,2
// pop edi
// mov byte ptr ds:[esi+184],al
// pop esi
// mov eax,2
// pop ebx
// ret 
// call ff8_en.47BD10
// push edi
// mov byte ptr ds:[1D9CEC9],3
// call <ff8_en.nullsub_21>
// mov eax,dword ptr ds:[1CDC6EC]
// mov ecx,dword ptr ds:[ebx*8+B8DBA4]
// mov edx,dword ptr ds:[ebx*8+B8DBA0]
// push eax
// push 1
// push ecx
// push edx
// call ff8_en.530460
// mov dword ptr ds:[1D9CF34],eax
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// dec bl
// mov cl,byte ptr ds:[eax+CC]
// push ebx
// dec cl
// push ecx
// call <ff8_en.PlayMovie>
// mov al,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,1C
// add al,FE
// mov byte ptr ds:[esi+184],al
// mov dword ptr ds:[edx+50],0
// pop edi
// pop esi
// mov eax,3
// pop ebx
// ret 
int SCRIPT_MOVIEREADY(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[1CD2EB0]
// test eax,eax
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// je ff8_en.51F3A5
// mov dword ptr ds:[eax+50],2710
// mov ecx,dword ptr ds:[eax+68]
// test ch,1
// je ff8_en.51F3B3
// mov eax,2
// ret 
// test byte ptr ds:[1D9CEC9],2
// jne ff8_en.51F3CB
// push 389
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// call ff8_en.530480
// test eax,eax
// je ff8_en.51F45E
// mov eax,dword ptr ds:[<entity_other>]
// xor ecx,ecx
// mov cl,byte ptr ds:[<entity_count_other>]
// test ecx,ecx
// jle ff8_en.51F426
// add eax,200
// mov dx,word ptr ds:[eax-2]
// add eax,264
// shl dx,1
// mov word ptr ds:[eax-266],dx
// mov dx,word ptr ds:[eax-264]
// shl dx,1
// mov word ptr ds:[eax-264],dx
// mov dx,word ptr ds:[eax-25C]
// shl dx,1
// mov word ptr ds:[eax-25C],dx
// dec ecx
// jne ff8_en.51F3EE
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[eax+68],10
// jne ff8_en.51F44E
// cmp word ptr ds:[eax+B8],0
// jle ff8_en.51F44E
// call ff8_en.4B86D0
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+B8],0
// call ff8_en.530490
// call <ff8_en.Movie_SetFrameLimiter>
// mov eax,2
// ret 
// mov eax,1
// ret 
int SCRIPT_MOVIE(FieldEntity& entity, int arg) {
    return 0;
}



// 0x51F470
// mov ecx,dword ptr ds:[<entity_other>]
// xor eax,eax
// mov al,byte ptr ds:[<entity_count_other>]
// test eax,eax
// jle ff8_en.51F4CA
// push esi
// add ecx,200
// mov esi,eax
// movsx eax,word ptr ds:[ecx-2]
// cdq 
// sub eax,edx
// add ecx,264
// sar eax,1
// mov word ptr ds:[ecx-266],ax
// movsx eax,word ptr ds:[ecx-264]
// cdq 
// sub eax,edx
// sar eax,1
// mov word ptr ds:[ecx-264],ax
// movsx eax,word ptr ds:[ecx-25C]
// cdq 
// sub eax,edx
// sar eax,1
// mov word ptr ds:[ecx-25C],ax
// dec esi
// jne ff8_en.51F48A
// pop esi
// mov al,byte ptr ds:[1CE4775]
// test al,al
// jne ff8_en.51F4DA
// mov byte ptr ds:[1CE4903],0
// mov byte ptr ds:[1D9CEC9],0
// ret 



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// test ch,1
// jne ff8_en.51F511
// call ff8_en.5305B0
// test eax,eax
// je ff8_en.51F50C
// mov eax,1
// ret 
// call ff8_en.55AA40
// mov eax,2
// ret 
int SCRIPT_MOVIESYNC(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// push edi
// mov edi,dword ptr ss:[esp+C]
// movsx eax,byte ptr ds:[edi+184]
// mov esi,dword ptr ds:[edi+eax*4]
// shl esi,1
// call ff8_en.47BD10
// push 10
// mov byte ptr ds:[1D9CEC9],3
// call <ff8_en.nullsub_21>
// mov ecx,dword ptr ds:[1CDC6EC]
// mov edx,dword ptr ds:[esi*8+B8DCAC]
// mov eax,dword ptr ds:[esi*8+B8DCA8]
// push ecx
// push 2
// push edx
// push eax
// call ff8_en.530460
// add esp,14
// call ff8_en.530490
// call ff8_en.46C8C0
// xor esi,esi
// mov dword ptr ds:[1CD2CA4],eax
// cmp eax,esi
// je ff8_en.51F588
// push esi
// push 2
// push 2
// call ff8_en.46C9B0
// add esp,C
// mov al,byte ptr ds:[edi+184]
// mov dword ptr ds:[1D9CDCC],esi
// dec al
// mov dword ptr ds:[1A78C38],esi
// mov byte ptr ds:[edi+184],al
// pop edi
// mov eax,3
// pop esi
// ret 
int SCRIPT_SPUREADY(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov ecx,dword ptr ds:[1D9CDCC]
// movsx eax,byte ptr ds:[esi+184]
// mov dword ptr ds:[1A78C38],ecx
// mov eax,dword ptr ds:[esi+eax*4]
// test eax,eax
// jle ff8_en.51F5DA
// cmp eax,ecx
// jb ff8_en.51F5EA
// mov eax,1
// pop esi
// ret 
// call ff8_en.5305C0
// test eax,eax
// je ff8_en.51F5EA
// mov eax,1
// pop esi
// ret 
// mov al,byte ptr ds:[esi+184]
// dec al
// mov byte ptr ds:[esi+184],al
// mov eax,2
// pop esi
// ret 
int SCRIPT_SPUSYNC(FieldEntity& entity, int arg) {
    return 0;
}

// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// or ch,1
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
int SCRIPT_MOVIECUT(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// or edx,1
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// push edx
// push esi
// push ff8_en.B8DCB0
// mov byte ptr ds:[ecx+184],al
// call ff8_en.4A29A0
// add esp,C
// mov dword ptr ds:[1D9CDE8],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_SETVIBRATE(FieldEntity& entity, int arg) {
    return 0;
}



int SCRIPT_STOPVIBRATE(FieldEntity& entity, int arg) {
    return 2;
}



int SCRIPT_LOADSYNC(FieldEntity& entity, int arg) {
    return 2;
}



// call <ff8_en.InitializeSound_CAL>
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+6C]
// cmp ecx,FFFFFFFF
// je ff8_en.51F6B2
// push 7F
// push ecx
// call ff8_en.46BB40
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,8
// mov ecx,dword ptr ds:[eax+70]
// cmp ecx,FFFFFFFF
// je ff8_en.51F6CA
// push 7F
// push ecx
// call ff8_en.46BB40
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,8
// mov byte ptr ds:[eax+C5],7F
// push 7F
// mov byte ptr ds:[eax+C6],7F
// call ff8_en.46B420
// push 80
// call ff8_en.46BF00
// add esp,8
// mov eax,2
// ret 
int SCRIPT_INITSOUND(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[esi+CB],dl
// mov eax,2
// pop esi
// ret 
int SCRIPT_SETBATTLEMUSIC(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov eax,1
// push esi
// mov cl,byte ptr ds:[edx+174]
// shl eax,cl
// mov cl,byte ptr ds:[edx+175]
// test cl,al
// je ff8_en.51F7CB
// mov al,byte ptr ds:[edx+184]
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// movsx ecx,al
// dec al
// mov byte ptr ds:[<isMusicLoaded>],0
// mov cl,byte ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov byte ptr ds:[esi+D5],cl
// mov eax,dword ptr ds:[esi+70]
// cmp eax,FFFFFFFF
// je ff8_en.51F782
// mov eax,2
// pop esi
// ret 
// mov al,byte ptr ds:[esi+CF]
// test al,al
// mov eax,dword ptr ds:[esi+68]
// je ff8_en.51F794
// and ah,FB
// jmp ff8_en.51F797
// or ah,4
// mov dword ptr ds:[esi+68],eax
// mov byte ptr ds:[esi+CF],1
// call ff8_en.47BD10
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,dword ptr ds:[1CDC6EC]
// push edx
// movsx ecx,byte ptr ds:[eax+D5]
// push ecx
// push 0
// call ff8_en.52CD10
// add esp,C
// mov byte ptr ds:[<isMusicLoaded>],1
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor eax,eax
// mov cl,byte ptr ds:[edx+D6]
// pop esi
// test cl,cl
// setne al
// inc eax
// ret 
int SCRIPT_MUSICLOAD(FieldEntity& entity, int arg) {
    return 0;
}



// mov al,byte ptr ds:[<isMusicLoaded>]
// test al,al
// jne ff8_en.51F7FF
// mov eax,2
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[<isMusicLoaded>],0
// mov cl,byte ptr ds:[eax+D5]
// mov byte ptr ds:[eax+C7],cl
// call <ff8_en.WM2Field_MusicAKAO>
// push eax
// call <ff8_en.PlayMusic_SdMusicPlay>
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor edx,edx
// mov dword ptr ds:[ecx+6C],eax
// mov dl,byte ptr ds:[ecx+C5]
// push edx
// push 0
// call ff8_en.46BB40
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov ecx,dword ptr ds:[eax+68]
// test ch,4
// je ff8_en.51F861
// mov byte ptr ds:[eax+CF],0
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
// mov byte ptr ds:[eax+CF],1
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
int SCRIPT_MUSICCHANGE(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[eax+C9]
// mov eax,<ff8_en.AKAO_Pointer>
// test cl,cl
// je ff8_en.51F899
// mov eax,<ff8_en.aAkao_0>
// push eax
// call <ff8_en.PlayMusic_SdMusicPlay>
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor edx,edx
// mov dword ptr ds:[ecx+6C],eax
// mov dl,byte ptr ds:[ecx+C5]
// push edx
// push 0
// call ff8_en.46BB40
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov ecx,dword ptr ds:[eax+68]
// test ch,4
// je ff8_en.51F8DE
// mov byte ptr ds:[eax+CF],0
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
// mov byte ptr ds:[eax+CF],1
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
int SCRIPT_MUSICREPLAY(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov al,byte ptr ds:[<isMusicLoaded>]
// test al,al
// jne ff8_en.51F927
// mov eax,2
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// push edx
// mov byte ptr ds:[<isMusicLoaded>],0
// mov cl,byte ptr ds:[eax+D5]
// mov byte ptr ds:[eax+C7],cl
// call <ff8_en.WM2Field_MusicAKAO>
// push eax
// call <ff8_en.PlayMusic_FromSingletonData>
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor edx,edx
// mov dword ptr ds:[ecx+6C],eax
// mov dl,byte ptr ds:[ecx+C5]
// push edx
// push 0
// call ff8_en.46BB40
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,10
// mov ecx,dword ptr ds:[eax+68]
// test ch,4
// je ff8_en.51F98A
// mov byte ptr ds:[eax+CF],0
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
// mov byte ptr ds:[eax+CF],1
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov eax,3
// ret 
int SCRIPT_MUSICSKIP(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,3FFFFFF
// dec al
// mov byte ptr ds:[ecx+184],al
// mov al,byte ptr ds:[<isMusicLoaded>]
// test al,al
// jne ff8_en.51F9DD
// mov eax,2
// pop esi
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// push esi
// push edx
// mov byte ptr ds:[<isMusicLoaded>],0
// mov cl,byte ptr ds:[eax+D5]
// mov byte ptr ds:[eax+C7],cl
// call <ff8_en.WM2Field_MusicAKAO>
// push eax
// call ff8_en.46B990
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov dword ptr ds:[ecx+6C],eax
// mov eax,dword ptr ds:[ecx+68]
// test ah,4
// je ff8_en.51FA2D
// mov byte ptr ds:[ecx+CF],0
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// pop esi
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret 
// mov byte ptr ds:[ecx+CF],1
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// pop esi
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret 
int SCRIPT_CHOICEMUSIC(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// shl edx,1
// dec al
// movsx esi,al
// mov byte ptr ds:[ecx+184],al
// mov esi,dword ptr ds:[ecx+esi*4]
// and esi,7F
// dec al
// mov byte ptr ds:[ecx+184],al
// mov al,byte ptr ds:[<isMusicLoaded>]
// test al,al
// jne ff8_en.51FA8C
// mov eax,2
// pop esi
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// push esi
// push edx
// mov byte ptr ds:[<isMusicLoaded>],0
// mov cl,byte ptr ds:[eax+D5]
// mov byte ptr ds:[eax+C7],cl
// call <ff8_en.WM2Field_MusicAKAO>
// push eax
// call <ff8_en.PlayMusic_FromSingleton>
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov dword ptr ds:[ecx+6C],eax
// mov eax,dword ptr ds:[ecx+68]
// test ah,4
// je ff8_en.51FADC
// mov byte ptr ds:[ecx+CF],0
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// pop esi
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret 
// mov byte ptr ds:[ecx+CF],1
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// pop esi
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret
int SCRIPT_CROSSMUSIC(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// mov ecx,dword ptr ds:[edx+ecx*4]
// and ecx,7F
// dec al
// mov byte ptr ds:[edx+184],al
// mov al,byte ptr ds:[<isMusicLoaded>]
// test al,al
// jne ff8_en.51FB2A
// mov eax,2
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[<isMusicLoaded>],0
// mov dl,byte ptr ds:[eax+D5]
// mov byte ptr ds:[eax+C8],dl
// mov dl,byte ptr ds:[eax+C9]
// test dl,dl
// mov eax,<ff8_en.AKAO_Pointer>
// jne ff8_en.51FB56
// mov eax,<ff8_en.aAkao_0>
// push ecx
// push eax
// call <ff8_en.PlayMusic_SecondChannel>
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,8
// mov dword ptr ds:[ecx+70],eax
// mov eax,dword ptr ds:[ecx+68]
// test ah,4
// je ff8_en.51FB87
// mov byte ptr ds:[ecx+CF],0
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret 
// mov byte ptr ds:[ecx+CF],1
// mov eax,dword ptr ds:[ecx+68]
// and ah,FB
// mov dword ptr ds:[ecx+68],eax
// mov eax,3
// ret 
int SCRIPT_DUALMUSIC(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call <ff8_en.xorEAX_0>
// add esp,4
// mov eax,2
// ret 
int SCRIPT_KEYSIGNCHANGE(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov esi,dword ptr ds:[ecx+edx*4]
// and esi,1
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov eax,dword ptr ds:[eax+esi*4+6C]
// cmp eax,FFFFFFFF
// je ff8_en.51FC18
// push eax
// call ff8_en.46B800
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,4
// mov dword ptr ds:[eax+esi*4+6C],FFFFFFFF
// mov byte ptr ds:[eax+esi+C7],FF
// mov eax,2
// pop esi
// ret 
int SCRIPT_MUSICSTOP(FieldEntity& entity, int arg) {
    return 0;
}



// call ff8_en.46B970
// mov ecx,dword ptr ss:[esp+4]
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
int SCRIPT_MUSICSTATUS(FieldEntity& entity, int arg) {
    return 0;
}



// call <ff8_en.xorEAX_0>
// mov ecx,dword ptr ss:[esp+4]
// mov edx,eax
// and eax,FFFF
// sar edx,10
// mov dword ptr ds:[ecx+144],eax
// mov dword ptr ds:[ecx+140],edx
// mov eax,2
// ret 
int SCRIPT_UNKNOWN10(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// push ebx
// push 10
// mov esi,dword ptr ds:[ecx+edx*4]
// and esi,1
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+esi*4+6C]
// push ecx
// call ff8_en.46BBC0
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov eax,2
// mov byte ptr ds:[edx+esi+C5],bl
// pop esi
// pop ebx
// ret 
int SCRIPT_MUSICVOL(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebx
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// mov esi,dword ptr ds:[eax+esi*4]
// and esi,1
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// lea eax,dword ptr ds:[edx+edx]
// mov edx,dword ptr ds:[ecx+esi*4+6C]
// push eax
// push edx
// call ff8_en.46BBC0
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,C
// mov byte ptr ds:[eax+esi+C5],bl
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_MUSICVOLTRANS(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebx
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// push edx
// mov edi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// mov esi,dword ptr ds:[eax+esi*4]
// and esi,1
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// lea eax,dword ptr ds:[edi+edi]
// mov edx,dword ptr ds:[ecx+esi*4+6C]
// push eax
// push edx
// call ff8_en.46BC50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,10
// mov byte ptr ds:[eax+esi+C5],bl
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
int SCRIPT_MUSICVOLFADE(FieldEntity& entity, int arg) {
    return 0;
}



// push 1
// call <ff8_en.xorEAX_0>
// add esp,4
// neg eax
// sbb eax,eax
// add eax,2
// ret 
int SCRIPT_MUSICVOLSYNC(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov eax,1
// mov cl,byte ptr ds:[edx+174]
// shl eax,cl
// mov cl,byte ptr ds:[edx+175]
// test cl,al
// je ff8_en.51FE8B
// mov al,byte ptr ds:[edx+184]
// push esi
// movsx ecx,al
// dec al
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// movsx edx,cl
// mov byte ptr ds:[esi+CA],cl
// mov byte ptr ds:[1D9CDE5],0
// mov eax,dword ptr ds:[edx*4+<&aXJppcSoundEffe>]
// push eax
// push <ff8_en.aSmeffectchange>
// call <ff8_en._printf>
// add esp,8
// call <ff8_en.xorEAX_0>
// test eax,eax
// pop esi
// je ff8_en.51FE52
// call <ff8_en.xorEAX_0>
// test eax,eax
// jne ff8_en.51FE49
// mov ecx,dword ptr ds:[1CDC6EC]
// push 1
// push ecx
// call <ff8_en.xorEAX_0>
// add esp,8
// cmp eax,FFFFFFFF
// jne ff8_en.51FE7E
// mov edx,dword ptr ds:[1CDC6EC]
// push 1
// push edx
// call <ff8_en.xorEAX_0>
// add esp,8
// cmp eax,FFFFFFFF
// je ff8_en.51FE68
// mov byte ptr ds:[1D9CDE5],1
// mov eax,2
// ret 
// mov al,byte ptr ds:[1D9CDE5]
// test al,al
// je ff8_en.51FE9A
// mov eax,2
// ret 
// mov eax,1
// ret 
int SCRIPT_EFFECTLOAD(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// push edx
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// push esi
// mov edi,dword ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// movsx ebx,cl
// dec cl
// push edi
// mov ebx,dword ptr ds:[eax+ebx*4]
// mov byte ptr ds:[eax+184],cl
// push ebx
// call <ff8_en.PlayWorldSound>
// add esp,10
// mov eax,2
// pop edi
// pop esi
// pop ebx
// ret 
int SCRIPT_EFFECTPLAY(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// sub esp,64
// mov cl,byte ptr ds:[eax+184]
// push esi
// movsx edx,cl
// push edi
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov eax,dword ptr ss:[esp+74]
// mov ecx,dword ptr ds:[1CE4A60]
// test eax,eax
// jl ff8_en.51FF72
// cmp eax,ecx
// ja ff8_en.51FF72
// mov eax,dword ptr ds:[eax*4+1CE4BFC]
// and esi,7F
// and edx,FF
// push esi
// push edx
// push edi
// push eax
// call <ff8_en.PlayWorldSound>
// add esp,10
// mov eax,2
// pop edi
// pop esi
// add esp,64
// ret 
// push ecx
// push eax
// push <ff8_en.aDdtower2>
// lea ecx,dword ptr ss:[esp+14]
// push <ff8_en.aErrorInvalidSf>
// push ecx
// call <ff8_en._sprintf>
// lea edx,dword ptr ss:[esp+1C]
// push edx
// call <ff8_en.OutputDebugString_1>
// add esp,18
// mov eax,2
// pop edi
// pop esi
// add esp,64
// ret 
int SCRIPT_EFFECTPLAY2(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call ff8_en.46B420
// add esp,4
// mov eax,2
// ret 
int SCRIPT_ALLSEVOL(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// lea eax,dword ptr ds:[edx+edx]
// push eax
// push esi
// call ff8_en.46BEC0
// add esp,8
// mov eax,2
// pop esi
// ret 
int SCRIPT_ALLSEVOLTRANS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call ff8_en.46BF00
// add esp,4
// mov eax,2
// ret 
int SCRIPT_ALLSEPOS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// lea eax,dword ptr ds:[edx+edx]
// push eax
// push esi
// call ff8_en.46BF30
// add esp,8
// mov eax,2
// pop esi
// ret 
int SCRIPT_ALLSEPOSTRANS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// push edx
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// push 0
// call ff8_en.46BD70
// add esp,C
// mov eax,2
// pop esi
// ret 
int SCRIPT_SEVOL(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// push edx
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov edi,dword ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[esi+esi]
// push eax
// push edi
// push 0
// call ff8_en.46BDA0
// add esp,10
// mov eax,2
// pop edi
// pop esi
// ret 
int SCRIPT_SEVOLTRANS(FieldEntity& entity, int arg) {
    return 0;
}



// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// push edx
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// push 0
// call ff8_en.46BDF0
// add esp,C
// mov eax,2
// pop esi
// ret 
int SCRIPT_SEPOS(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// push edx
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov edi,dword ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[esi+esi]
// push eax
// push edi
// push 0
// call ff8_en.46BE20
// add esp,10
// mov eax,2
// pop edi
// pop esi
// ret 
int SCRIPT_SEPOSTRANS(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov edx,1
// push edi
// movsx eax,byte ptr ds:[esi+184]
// mov cl,byte ptr ds:[esi+174]
// mov edi,dword ptr ds:[esi+eax*4]
// mov al,byte ptr ds:[esi+175]
// shl edx,cl
// test al,dl
// je ff8_en.5201D2
// push edi
// push 0
// call ff8_en.46B450
// add esp,8
// call <ff8_en.xorEAX_0>
// test edi,eax
// jne ff8_en.5201F1
// mov al,byte ptr ds:[esi+184]
// pop edi
// dec al
// mov byte ptr ds:[esi+184],al
// mov eax,2
// pop esi
// ret 
// pop edi
// mov eax,1
// pop esi
// ret 
int SCRIPT_SESTOP(FieldEntity& entity, int arg) {
    return 0;
}



// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call <ff8_en.SdEffectAttrCheck>
// add esp,4
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
int SCRIPT_UNKNOWN13(FieldEntity& entity, int arg) {
    return 0;
}



// mov edx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// not ecx
// mov dword ptr ds:[1CE4914],ecx
// mov eax,2
// ret 
int SCRIPT_UNKNOWN14(FieldEntity& entity, int arg) {
    return 0;
}



// 0x520260
// sub esp,10
// push edi
// mov edi,dword ptr ss:[esp+18]
// test byte ptr ds:[edi+160],80
// je ff8_en.52044F
// xor eax,eax
// push esi
// mov al,byte ptr ds:[edi+256]
// push 0
// mov esi,eax
// push 0
// push 1F
// push esi
// call ff8_en.531DA0
// push eax
// call <ff8_en.sub_56BAE0>
// push 0
// push 0
// push 1F
// push esi
// call ff8_en.531DA0
// push eax
// call ff8_en.56BB30
// lea ecx,dword ptr ss:[esp+30]
// lea edx,dword ptr ss:[esp+34]
// push ecx
// lea eax,dword ptr ss:[esp+48]
// push edx
// lea ecx,dword ptr ss:[esp+40]
// push eax
// push ecx
// mov word ptr ss:[esp+48],0
// mov word ptr ss:[esp+4A],0
// mov word ptr ss:[esp+4C],0
// call ff8_en.56C880
// mov esi,eax
// add esp,38
// movsx eax,word ptr ss:[esp+1C]
// cmp eax,FFFFFE00
// jge ff8_en.5202EA
// mov eax,FFFFFE00
// jmp ff8_en.5202F6
// cmp eax,1FC
// jl ff8_en.5202F6
// mov eax,1FC
// cdq 
// and edx,3
// add eax,edx
// mov ecx,eax
// mov eax,2AAAAAAB
// imul esi
// sar edx,2
// mov eax,edx
// pop esi
// shr eax,1F
// sar ecx,2
// add edx,eax
// add ecx,80
// cmp edx,8
// mov dword ptr ss:[esp+18],ecx
// jge ff8_en.520329
// mov edx,8
// jmp ff8_en.520333
// cmp edx,6E
// jl ff8_en.520333
// mov edx,6E
// mov eax,7F
// sub eax,edx
// mov edx,dword ptr ss:[esp+1C]
// sub edx,0
// je ff8_en.5203D1
// dec edx
// jne ff8_en.52044F
// mov dl,byte ptr ds:[edi+23C]
// cmp dl,3
// je ff8_en.5203BB
// cmp dl,4
// je ff8_en.5203BB
// mov dl,byte ptr ds:[edi+189]
// cmp dl,FF
// je ff8_en.520388
// push eax
// push ecx
// movsx ecx,dl
// push ff8_en.800000
// mov edx,dword ptr ds:[ecx*4+1CE4BFC]
// push edx
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// mov edx,dword ptr ds:[edi+160]
// push eax
// test edx,4000000
// push ecx
// push ff8_en.400000
// je ff8_en.5203AC
// push 35
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// push 2
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// push eax
// push ecx
// push ff8_en.400000
// push 3F
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// mov dl,byte ptr ds:[edi+23C]
// cmp dl,3
// je ff8_en.52043E
// cmp dl,4
// je ff8_en.52043E
// mov dl,byte ptr ds:[edi+188]
// cmp dl,FF
// je ff8_en.52040B
// push eax
// push ecx
// movsx eax,dl
// push ff8_en.400000
// mov ecx,dword ptr ds:[eax*4+1CE4BFC]
// push ecx
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// mov edx,dword ptr ds:[edi+160]
// push eax
// test edx,4000000
// push ecx
// push ff8_en.400000
// je ff8_en.52042F
// push 36
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// push 3
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 
// push eax
// push ecx
// push ff8_en.400000
// push 40
// call <ff8_en.PlayWorldSound>
// add esp,10
// pop edi
// add esp,10
// ret 



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,byte ptr ss:[esp+8]
// mov byte ptr ds:[eax+188],dl
// mov byte ptr ds:[eax+189],cl
// mov eax,2
// ret 
int SCRIPT_FOOTSTEP(FieldEntity& entity, int arg) {
    return 0;
}



// xor ecx,ecx
// push esi
// mov cl,byte ptr ds:[<entity_count_other>]
// mov esi,dword ptr ds:[<entity_other>]
// test ecx,ecx
// jle ff8_en.5204CF
// mov eax,dword ptr ss:[esp+8]
// push ebx
// mov dl,byte ptr ds:[eax+188]
// mov bl,byte ptr ds:[eax+189]
// lea eax,dword ptr ds:[esi+189]
// mov byte ptr ds:[eax-1],dl
// mov byte ptr ds:[eax],bl
// add eax,264
// dec ecx
// jne ff8_en.5204BA
// pop ebx
// mov eax,2
// pop esi
// ret 
// mov eax,2
// pop esi
// ret 
int SCRIPT_FOOTSTEPCOPY(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// or cl,80
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret 
int SCRIPT_FOOTSTEPON(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// and cl,7F
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret 
int SCRIPT_FOOTSTEPOFF(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ds:[<entity_other>]
// xor ecx,ecx
// mov cl,byte ptr ds:[<entity_count_other>]
// test ecx,ecx
// jle ff8_en.520549
// add eax,160
// mov edx,dword ptr ds:[eax]
// add eax,264
// and dl,7F
// dec ecx
// mov dword ptr ds:[eax-264],edx
// jne ff8_en.520536
// mov eax,2
// ret 
int SCRIPT_FOOTSTEPOFFALL(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// or cl,FF
// mov byte ptr ds:[eax+188],cl
// mov byte ptr ds:[eax+189],cl
// mov eax,2
// ret 
int SCRIPT_FOOTSTEPCUT(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.520624
// push ebx
// mov bl,byte ptr ds:[eax+184]
// movsx edx,bl
// push ebp
// mov ebp,dword ptr ds:[eax+160]
// lea ecx,dword ptr ds:[eax+edx*4]
// push esi
// push edi
// and ebp,FFFF06FF
// mov esi,dword ptr ds:[ecx-4]
// mov edi,dword ptr ds:[ecx]
// mov ecx,esi
// mov edx,edi
// shl ecx,6
// shl edx,6
// cmp edi,esi
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+18C],cx
// mov word ptr ds:[eax+18E],dx
// mov word ptr ds:[eax+188],cx
// jge ff8_en.5205F8
// or ebp,100
// add ecx,3F
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+188],cx
// mov word ptr ds:[eax+18C],cx
// jmp ff8_en.520602
// add edx,3F
// mov word ptr ds:[eax+18E],dx
// mov ecx,dword ptr ds:[eax+160]
// sub bl,2
// or ch,80
// pop edi
// pop esi
// mov byte ptr ds:[eax+184],bl
// mov dword ptr ds:[eax+160],ecx
// pop ebp
// pop ebx
// mov eax,1
// ret 
// mov ecx,dword ptr ds:[eax+160]
// mov eax,2
// test ch,8
// jne ff8_en.520639
// mov eax,1
// ret 
int SCRIPT_BGANIME(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov bl,byte ptr ds:[eax+184]
// mov ebp,dword ptr ds:[eax+160]
// movsx ecx,bl
// mov esi,dword ptr ds:[eax+ecx*4-4]
// push edi
// mov edi,dword ptr ds:[eax+ecx*4]
// lea ecx,dword ptr ds:[eax+ecx*4]
// mov ecx,esi
// mov edx,edi
// and ebp,FFFF06FF
// shl ecx,6
// shl edx,6
// cmp edi,esi
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+18C],cx
// mov word ptr ds:[eax+18E],dx
// mov word ptr ds:[eax+188],cx
// jge ff8_en.5206AF
// or ebp,100
// add ecx,3F
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+188],cx
// mov word ptr ds:[eax+18C],cx
// jmp ff8_en.5206B9
// add edx,3F
// mov word ptr ds:[eax+18E],dx
// mov ecx,dword ptr ds:[eax+160]
// sub bl,2
// or ch,80
// pop edi
// pop esi
// mov byte ptr ds:[eax+184],bl
// mov dword ptr ds:[eax+160],ecx
// pop ebp
// mov eax,2
// pop ebx
// ret 
int SCRIPT_RBGANIME(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov bl,byte ptr ds:[eax+184]
// mov ebp,dword ptr ds:[eax+160]
// movsx ecx,bl
// mov esi,dword ptr ds:[eax+ecx*4-4]
// push edi
// mov edi,dword ptr ds:[eax+ecx*4]
// lea ecx,dword ptr ds:[eax+ecx*4]
// mov ecx,esi
// mov edx,edi
// and ebp,FFFF06FF
// shl ecx,6
// shl edx,6
// cmp edi,esi
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+18C],cx
// mov word ptr ds:[eax+18E],dx
// mov word ptr ds:[eax+188],cx
// jge ff8_en.52074F
// or ebp,100
// add ecx,3F
// mov dword ptr ds:[eax+160],ebp
// mov word ptr ds:[eax+188],cx
// mov word ptr ds:[eax+18C],cx
// jmp ff8_en.520759
// add edx,3F
// mov word ptr ds:[eax+18E],dx
// mov ecx,dword ptr ds:[eax+160]
// sub bl,2
// or ch,20
// pop edi
// pop esi
// mov byte ptr ds:[eax+184],bl
// mov dword ptr ds:[eax+160],ecx
// pop ebp
// mov eax,2
// pop ebx
// ret 
int SCRIPT_RBGANIMELOOP(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov eax,dword ptr ds:[eax+160]
// and eax,800
// neg eax
// sbb eax,eax
// neg eax
// inc eax
// ret 
int SCRIPT_BGANIMESYNC(FieldEntity& entity, int arg) {
    return 0;
}



// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov ecx,edx
// shl ecx,6
// mov word ptr ds:[eax+18C],cx
// mov word ptr ds:[eax+188],cx
// add ecx,3F
// mov word ptr ds:[eax+18E],cx
// mov ecx,1
// mov word ptr ds:[eax+192],cx
// mov word ptr ds:[eax+190],cx
// mov ecx,dword ptr ds:[eax+160]
// and ch,16
// or ch,10
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret 
// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// mov word ptr ds:[eax+188],FFFF
// and ch,16
// or ch,10
// mov dword ptr ds:[eax+160],ecx
// xor ecx,ecx
// mov word ptr ds:[eax+18E],cx
// mov word ptr ds:[eax+18C],cx
// mov ecx,1
// mov word ptr ds:[eax+192],cx
// mov word ptr ds:[eax+190],cx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,dx
// mov word ptr ds:[eax+192],dx
// mov word ptr ds:[eax+190],cx
// mov eax,2
// ret 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[ecx+194],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.520981
// mov ecx,dword ptr ds:[eax+160]
// mov word ptr ds:[eax+19E],0
// and ch,F9
// mov dword ptr ds:[eax+160],ecx
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AC],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AB],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AA],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A9],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A8],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A7],dl
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+19C],dx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+19C],0
// mov eax,2
// je ff8_en.520995
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// mov word ptr ds:[eax+19E],0
// or ch,6
// mov dword ptr ds:[eax+160],ecx
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A6],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A5],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AC],dl
// mov byte ptr ds:[eax+1B2],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AB],dl
// mov byte ptr ds:[eax+1B1],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1AA],dl
// mov byte ptr ds:[eax+1B0],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A9],dl
// mov byte ptr ds:[eax+1AF],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A8],dl
// mov byte ptr ds:[eax+1AE],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+1A7],dl
// mov byte ptr ds:[eax+1AD],dl
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1A2],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1A0],dx
// mov cx,dx
// mov dl,byte ptr ds:[eax+1A5]
// mov word ptr ds:[eax+19C],cx
// mov byte ptr ds:[eax+1A4],dl
// mov eax,2
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// mov word ptr ds:[eax+19C],0
// and ch,F9
// mov dword ptr ds:[eax+160],ecx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// and ch,F9
// mov dword ptr ds:[eax+160],ecx
// xor ecx,ecx
// mov word ptr ds:[eax+19E],cx
// mov byte ptr ds:[eax+1A6],cl
// mov byte ptr ds:[eax+1A5],cl
// mov byte ptr ds:[eax+1AC],cl
// mov byte ptr ds:[eax+1B2],cl
// mov byte ptr ds:[eax+1AB],cl
// mov byte ptr ds:[eax+1B1],cl
// mov byte ptr ds:[eax+1AA],cl
// mov byte ptr ds:[eax+1B0],cl
// mov byte ptr ds:[eax+1A9],cl
// mov byte ptr ds:[eax+1AF],cl
// mov byte ptr ds:[eax+1A8],cl
// mov byte ptr ds:[eax+1AE],cl
// mov byte ptr ds:[eax+1A7],cl
// mov byte ptr ds:[eax+1AD],cl
// mov word ptr ds:[eax+1A2],cx
// mov word ptr ds:[eax+1A0],cx
// mov word ptr ds:[eax+19C],cx
// mov byte ptr ds:[eax+1A4],cl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov al,1
// mov byte ptr ds:[1CE4882],al
// mov byte ptr ds:[1CE4890],al
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE489A],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4894],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE488C],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4886],dx
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// xor al,al
// mov byte ptr ds:[1CE4882],al
// mov byte ptr ds:[1CE4890],al
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov byte ptr ds:[1CE4782],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CE4792],dx
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,3
// mov word ptr ds:[1CE4790],dx
// mov byte ptr ds:[1CE4780],al
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[1CE4780],4
// mov byte ptr ds:[1CE4782],0
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4784],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4792],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4790],dx
// mov eax,2
// ret 
// mov eax,dword ptr ss:[esp+4]
// mov byte ptr ds:[1CE4780],5
// mov byte ptr ds:[1CE4782],0
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4784],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4792],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4790],dx
// mov eax,2
// ret 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[edx*4+1D9D020]
// mov cl,byte ptr ds:[eax+256]
// xor al,al
// mov byte ptr ds:[1CE4780],al
// mov byte ptr ds:[1CE4782],al
// mov byte ptr ds:[1CE4781],cl
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov byte ptr ds:[1CE4780],1
// mov byte ptr ds:[1CE4782],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// dec al
// mov word ptr ds:[1CE4784],dx
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[esi*4+1D9D020]
// pop esi
// mov cl,byte ptr ds:[eax+256]
// mov eax,2
// mov byte ptr ds:[1CE4781],cl
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov byte ptr ds:[1CE4782],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// dec al
// mov word ptr ds:[1CE4784],dx
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[esi*4+1D9D020]
// pop esi
// mov cl,byte ptr ds:[eax+256]
// mov eax,2
// mov byte ptr ds:[1CE4781],cl
// mov byte ptr ds:[1CE4780],al
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// xor al,al
// mov dl,byte ptr ds:[edx+esi+C2]
// mov byte ptr ds:[1CE4780],al
// mov byte ptr ds:[1CE4782],al
// mov byte ptr ds:[1CE4781],dl
// mov eax,3
// pop esi
// ret 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[1CE4780],1
// mov al,byte ptr ds:[ecx+184]
// mov byte ptr ds:[1CE4782],0
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CE4784],dx
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// mov dl,byte ptr ds:[edx+esi+C2]
// pop esi
// mov byte ptr ds:[1CE4781],dl
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[1CE4782],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CE4784],dx
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// mov dl,byte ptr ds:[edx+esi+C2]
// mov byte ptr ds:[1CE4780],al
// mov byte ptr ds:[1CE4781],dl
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov cl,byte ptr ds:[1CE4782]
// xor eax,eax
// cmp cl,2
// sete al
// inc eax
// ret 
// mov edx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// mov ecx,dword ptr ds:[edx+ecx*4]
// lea esi,dword ptr ds:[ecx*8]
// sub esi,ecx
// mov cl,byte ptr ds:[esi*4+1CE4782]
// pop esi
// cmp cl,2
// jne ff8_en.520F95
// dec al
// mov byte ptr ds:[edx+184],al
// mov eax,2
// ret 
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4792],si
// mov word ptr ds:[eax+1CE4790],di
// mov byte ptr ds:[eax+1CE4780],3
// mov byte ptr ds:[eax+1CE4782],0
// pop edi
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov word ptr ds:[eax+1CE4792],di
// mov word ptr ds:[eax+1CE4790],bx
// mov byte ptr ds:[eax+1CE4780],4
// pop edi
// mov byte ptr ds:[eax+1CE4782],0
// pop esi
// mov eax,2
// pop ebx
// ret 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov word ptr ds:[eax+1CE4792],di
// mov word ptr ds:[eax+1CE4790],bx
// mov byte ptr ds:[eax+1CE4780],5
// pop edi
// mov byte ptr ds:[eax+1CE4782],0
// pop esi
// mov eax,2
// pop ebx
// ret 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov ecx,dword ptr ds:[esi*4+1D9D020]
// pop esi
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// mov dl,byte ptr ds:[ecx+256]
// shl eax,2
// xor cl,cl
// mov byte ptr ds:[eax+1CE4781],dl
// mov byte ptr ds:[eax+1CE4780],cl
// mov byte ptr ds:[eax+1CE4782],cl
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[edi*4+1D9D020]
// pop edi
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// mov dl,byte ptr ds:[ecx+256]
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov byte ptr ds:[eax+1CE4781],dl
// mov byte ptr ds:[eax+1CE4780],1
// mov byte ptr ds:[eax+1CE4782],0
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[edi*4+1D9D020]
// pop edi
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// mov dl,byte ptr ds:[ecx+256]
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov byte ptr ds:[eax+1CE4781],dl
// mov byte ptr ds:[eax+1CE4780],2
// mov byte ptr ds:[eax+1CE4782],0
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov bl,byte ptr ds:[edx+esi+C2]
// pop esi
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// xor cl,cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov byte ptr ds:[eax+1CE4781],bl
// mov byte ptr ds:[eax+1CE4780],cl
// mov byte ptr ds:[eax+1CE4782],cl
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// mov edi,dword ptr ds:[<&SG_FIELD_VARS>]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov bl,byte ptr ds:[edx+edi+C2]
// pop edi
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov byte ptr ds:[eax+1CE4781],bl
// mov byte ptr ds:[eax+1CE4780],1
// mov byte ptr ds:[eax+1CE4782],0
// pop esi
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// mov edi,dword ptr ds:[<&SG_FIELD_VARS>]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov bl,byte ptr ds:[edx+edi+C2]
// pop edi
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4784],si
// mov byte ptr ds:[eax+1CE4781],bl
// mov byte ptr ds:[eax+1CE4780],2
// mov byte ptr ds:[eax+1CE4782],0
// pop esi
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bp,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4794],bp
// mov word ptr ds:[eax+1CE4796],bx
// mov word ptr ds:[eax+1CE4798],di
// mov word ptr ds:[eax+1CE479A],si
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4798],di
// mov word ptr ds:[eax+1CE479A],si
// pop edi
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4790],di
// mov word ptr ds:[eax+1CE4792],si
// mov byte ptr ds:[eax+1CE4780],3
// mov byte ptr ds:[eax+1CE4782],0
// pop edi
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bp,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ss:[esp+14],dx
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+14]
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4788],cx
// mov word ptr ds:[eax+1CE478A],bp
// mov word ptr ds:[eax+1CE4790],bx
// mov word ptr ds:[eax+1CE4792],di
// mov word ptr ds:[eax+1CE4784],si
// pop edi
// mov byte ptr ds:[eax+1CE4780],4
// pop esi
// mov byte ptr ds:[eax+1CE4782],0
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov bp,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ss:[esp+14],dx
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+14]
// lea eax,dword ptr ds:[edx*8]
// sub eax,edx
// shl eax,2
// mov word ptr ds:[eax+1CE4788],cx
// mov word ptr ds:[eax+1CE478A],bp
// mov word ptr ds:[eax+1CE4790],bx
// mov word ptr ds:[eax+1CE4792],di
// mov word ptr ds:[eax+1CE4784],si
// pop edi
// mov byte ptr ds:[eax+1CE4780],5
// pop esi
// mov byte ptr ds:[eax+1CE4782],0
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[1CE490A],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov dword ptr ds:[<SG_COUNTDOWN>],edx
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<SG_COUNTDOWN>]
// mov ecx,dword ptr ss:[esp+4]
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[esi+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],cl
// mov byte ptr ds:[eax+CE],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],cl
// mov byte ptr ds:[eax+CD],dl
// mov esi,dword ptr ds:[eax+68]
// or esi,40
// mov ecx,4
// or word ptr ds:[1CFF6E2],cx
// mov dword ptr ds:[eax+68],esi
// or word ptr ds:[eax+B6],cx
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+CE]
// xor edx,edx
// mov dl,byte ptr ds:[eax+CD]
// push ecx
// push edx
// call <ff8_en.sub_4A6CE0>
// push 1
// call <ff8_en.ShowCountdownTimer>
// add esp,C
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// push 0
// mov ecx,dword ptr ds:[eax+68]
// and ecx,FFFFFFBF
// mov dword ptr ds:[eax+68],ecx
// mov ecx,FFFB
// and word ptr ds:[eax+B6],cx
// and word ptr ds:[1CFF6E2],cx
// call <ff8_en.ShowCountdownTimer>
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call <ff8_en.Set1D2B814>
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5218D8
// mov cl,byte ptr ds:[1CE4902]
// test cl,cl
// je ff8_en.52185E
// mov cl,byte ptr ds:[eax+184]
// add cl,FD
// mov byte ptr ds:[eax+184],cl
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[<globalFieldNextModuleID>],7
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE476E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE476C],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[<MenuState>],dx
// mov ecx,dword ptr ds:[eax+68]
// mov cl,byte ptr ds:[eax+D1]
// test ch,2
// je ff8_en.5218CF
// and cl,FD
// mov byte ptr ds:[eax+D1],cl
// mov eax,1
// ret 
// or cl,2
// mov byte ptr ds:[eax+D1],cl
// mov eax,1
// ret 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// xor esi,esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov dl,byte ptr ds:[ecx+edx*4]
// and dl,3
// dec al
// mov byte ptr ds:[ecx+184],al
// mov al,byte ptr ds:[<entity_count_other>]
// test al,al
// mov byte ptr ds:[1CE4906],dl
// jbe ff8_en.521928
// push 0
// push 0
// push 25
// push esi
// call ff8_en.532340
// xor eax,eax
// add esp,10
// mov al,byte ptr ds:[<entity_count_other>]
// inc esi
// cmp esi,eax
// jl ff8_en.52190D
// mov eax,2
// pop esi
// ret 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[1CE4907],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ds:[1CDC744]
// xor ecx,ecx
// cmp word ptr ds:[esi+76],7FFF
// lea eax,dword ptr ds:[esi+76]
// je ff8_en.52197F
// add eax,20
// inc ecx
// cmp word ptr ds:[eax],7FFF
// jne ff8_en.521974
// mov eax,dword ptr ss:[esp+8]
// shl ecx,5
// mov dl,byte ptr ds:[eax+184]
// add ecx,esi
// movsx esi,dl
// dec dl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],dl
// mov word ptr ds:[ecx+68],si
// movsx esi,dl
// dec dl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],dl
// mov word ptr ds:[ecx+66],si
// movsx esi,dl
// dec dl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],dl
// mov word ptr ds:[ecx+64],si
// movsx esi,dl
// dec dl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],dl
// mov word ptr ds:[ecx+76],si
// mov word ptr ds:[ecx+74],FFFF
// mov word ptr ds:[ecx+96],7FFF
// mov eax,2
// pop esi
// ret 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call <ff8_en.nullsub_33>
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.521AAC
// mov dx,word ptr ss:[esp+8]
// mov cl,byte ptr ds:[eax+184]
// mov word ptr ds:[1CE476C],dx
// mov byte ptr ds:[<globalFieldNextModuleID>],1
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE476E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4766],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4764],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[<MenuState>],dx
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.521B66
// mov dx,word ptr ss:[esp+8]
// mov cl,byte ptr ds:[eax+184]
// mov word ptr ds:[1CE476C],dx
// mov byte ptr ds:[<globalFieldNextModuleID>],1
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE476E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4768],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4766],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4764],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[<MenuState>],dx
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.521C1D
// mov dx,word ptr ss:[esp+8]
// mov cl,byte ptr ds:[eax+184]
// mov word ptr ds:[1CE476C],dx
// mov byte ptr ds:[<globalFieldNextModuleID>],6
// movsx edx,cl
// dec cl
// mov byte ptr ds:[1CE4900],1
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE476E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4768],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4766],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4764],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[<MenuState>],dx
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov edx,dword ptr ss:[esp+4]
// mov eax,1
// mov cl,byte ptr ds:[edx+174]
// shl eax,cl
// mov cl,byte ptr ds:[edx+175]
// test cl,al
// je ff8_en.521CA0
// mov al,byte ptr ds:[edx+184]
// mov byte ptr ds:[<globalFieldNextModuleID>],1
// movsx ecx,al
// dec al
// mov word ptr ds:[1CE476E],0
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[1CE476C],cx
// mov ecx,7FFF
// mov word ptr ds:[1CE4764],cx
// mov word ptr ds:[1CE4766],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[<MenuState>],cx
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4902],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4902],1
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4905],1
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4905],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4903],1
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4903],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],0
// mov cl,byte ptr ds:[eax+D1]
// mov eax,3
// mov byte ptr ds:[1CE490B],cl
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],1
// mov byte ptr ds:[1CE490B],2
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],17
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[1CE490B],dl
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov byte ptr ds:[1CE490B],1
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// cmp edx,14
// ja ff8_en.521FB0
// jmp dword ptr ds:[edx*4+521FB8]
// mov word ptr ds:[<MenuState>],2
// mov eax,3
// ret 
// mov word ptr ds:[<MenuState>],3
// mov eax,3
// ret 
// mov word ptr ds:[<MenuState>],4
// mov eax,3
// ret 
// push 0
// mov word ptr ds:[<MenuState>],5
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 1
// mov word ptr ds:[<MenuState>],6
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 2
// mov word ptr ds:[<MenuState>],7
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 3
// mov word ptr ds:[<MenuState>],8
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 4
// mov word ptr ds:[<MenuState>],9
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 5
// mov word ptr ds:[<MenuState>],A
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 6
// mov word ptr ds:[<MenuState>],B
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 7
// mov word ptr ds:[<MenuState>],C
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 8
// mov word ptr ds:[<MenuState>],D
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push 9
// mov word ptr ds:[<MenuState>],E
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push A
// mov word ptr ds:[<MenuState>],F
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push B
// mov word ptr ds:[<MenuState>],10
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push C
// mov word ptr ds:[<MenuState>],11
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push D
// mov word ptr ds:[<MenuState>],12
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push E
// mov word ptr ds:[<MenuState>],13
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// push F
// mov word ptr ds:[<MenuState>],14
// call <ff8_en.SetGFExists>
// add esp,4
// mov eax,3
// ret 
// mov word ptr ds:[<MenuState>],1B
// call ff8_en.4AD360
// mov eax,3
// ret 
// mov word ptr ds:[<MenuState>],1C
// mov eax,3
// ret 
// mov edi,edi
// dd 521DD6
// dd 521DE5
// dd 521DF4
// dd 521E03
// dd 521E1C
// dd 521E35
// dd 521E4E
// dd 521E67
// dd 521E99
// dd 521E80
// dd 521EB2
// dd 521ECB
// dd 521EE4
// dd 521EFD
// dd 521F2F
// dd 521F16
// dd 521F48
// dd 521F61
// dd 521F7A
// dd 521F93
// dd 521FA7
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],1A
// mov byte ptr ds:[1CE490B],1
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],1D
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[1CE490B],dl
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov edx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// mov ecx,dword ptr ds:[edx+ecx*4]
// and ecx,7F
// dec al
// push ecx
// mov byte ptr ds:[edx+184],al
// call ff8_en.4AD170
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// call <ff8_en.REST>
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// push edi
// xor ecx,ecx
// mov edx,FFFE
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// cmp al,FF
// je ff8_en.5220F8
// and eax,FF
// lea edi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edi*2]
// cmp word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],0
// jne ff8_en.5220F8
// mov word ptr ds:[eax*8+<SG_CHARACTER_CURRENT_HP>],1
// xor eax,eax
// mov al,byte ptr ds:[ecx+<SG_PARTY_BATTLE1>]
// lea edi,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[eax+edi*2]
// and word ptr ds:[eax*8+<SG_CHARACTER_STATUS>],dx
// inc ecx
// cmp ecx,3
// jl ff8_en.5220B8
// mov eax,2
// pop edi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov si,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// lea eax,dword ptr ds:[edx+edx*8]
// lea ecx,dword ptr ds:[edx+eax*2]
// mov eax,2
// mov word ptr ds:[ecx*8+<SG_CHARACTER_CURRENT_HP>],si
// pop esi
// ret 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// lea eax,dword ptr ds:[edx+edx*8]
// lea edx,dword ptr ds:[edx+eax*2]
// xor eax,eax
// mov ax,word ptr ds:[edx*8+<SG_CHARACTER_CURRENT_HP>]
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[<globalFieldNextModuleID>],5
// mov word ptr ds:[<MenuState>],18
// mov byte ptr ds:[1CE490B],1
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test edx,edx
// mov cl,byte ptr ds:[eax+D1]
// je ff8_en.5221E6
// or cl,1
// mov byte ptr ds:[eax+D1],cl
// mov eax,2
// ret 
// and cl,FE
// mov byte ptr ds:[eax+D1],cl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// mov cl,byte ptr ds:[eax+D1]
// test ch,2
// je ff8_en.52221D
// and cl,FD
// mov byte ptr ds:[eax+D1],cl
// ret 
// or cl,2
// mov byte ptr ds:[eax+D1],cl
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test edx,edx
// je ff8_en.522260
// mov ecx,dword ptr ds:[eax+68]
// and ch,FD
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
// mov edx,dword ptr ds:[eax+68]
// or dh,2
// mov dword ptr ds:[eax+68],edx
// mov cl,byte ptr ds:[eax+D1]
// and cl,FD
// mov byte ptr ds:[eax+D1],cl
// mov eax,2
// ret 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// test ch,2
// jne ff8_en.5222C7
// mov cl,byte ptr ds:[eax+D1]
// test edx,edx
// je ff8_en.5222BE
// or cl,2
// mov byte ptr ds:[eax+D1],cl
// mov eax,2
// ret 
// and cl,FD
// mov byte ptr ds:[eax+D1],cl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// push edx
// call ff8_en.52CC50
// and eax,FF
// add esp,4
// mov esi,eax
// cmp esi,FF
// je ff8_en.522341
// xor ebp,ebp
// test edi,edi
// jle ff8_en.522341
// xor eax,eax
// push ebx
// mov al,byte ptr ds:[esi+<SG_PARTY_BATTLE1>]
// push eax
// call <ff8_en.MagicCountingRelated>
// add esp,8
// test eax,eax
// jne ff8_en.522341
// inc ebp
// cmp ebp,edi
// jl ff8_en.522326
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call ff8_en.56DAF0
// add esp,4
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx esi,al
// dec al
// mov esi,dword ptr ds:[ecx+esi*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// push edx
// call <ff8_en.sub_47ED00>
// add esp,8
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<SG_GIL>]
// add eax,edx
// cmp eax,5F5E0FF
// mov dword ptr ds:[<SG_GIL>],eax
// jb ff8_en.522404
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov eax,5F5E0FF
// mov dword ptr ds:[<SG_GIL>],eax
// mov dword ptr ds:[ecx+48],eax
// mov eax,2
// ret 
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dword ptr ds:[edx+48],eax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<SG_GIL_LAGUNA>]
// add eax,edx
// cmp eax,5F5E0FF
// mov dword ptr ds:[<SG_GIL_LAGUNA>],eax
// jb ff8_en.522464
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov eax,5F5E0FF
// mov dword ptr ds:[<SG_GIL_LAGUNA>],eax
// mov dword ptr ds:[ecx+4C],eax
// mov eax,2
// ret 
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dword ptr ds:[edx+4C],eax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add word ptr ds:[eax+10],dx
// mov cx,word ptr ds:[eax+10]
// cmp cx,64
// jge ff8_en.5224B7
// mov word ptr ds:[eax+10],64
// mov eax,2
// ret 
// cmp cx,C1C
// jl ff8_en.5224C4
// mov word ptr ds:[eax+10],C1C
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call ff8_en.534840
// add esp,4
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// push edx
// push ecx
// call ff8_en.5347F0
// add esp,8
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call ff8_en.534950
// add esp,4
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// push ecx
// call ff8_en.534A20
// add esp,4
// mov dword ptr ds:[esi+140],eax
// mov eax,2
// pop esi
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.522734
// mov al,byte ptr ds:[esi+184]
// movsx edx,al
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov byte ptr ds:[1DCD7B0],cl
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov byte ptr ds:[1DCD7AE],cl
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov byte ptr ds:[1DCD7AF],cl
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov byte ptr ds:[1DCD7B1],cl
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov byte ptr ds:[1DCD7AC],cl
// dec al
// mov ecx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov dword ptr ds:[1DCD7A8],ecx
// dec al
// mov cl,byte ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// mov byte ptr ds:[1DCD7AD],cl
// call ff8_en.5349B0
// cmp eax,5
// mov dword ptr ds:[esi+140],eax
// mov dword ptr ds:[esi+144],0
// jl ff8_en.52272D
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[eax+68],10
// jne ff8_en.522699
// cmp word ptr ds:[eax+B8],0
// jle ff8_en.522699
// call ff8_en.4B86D0
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[edx+B8],0
// mov byte ptr ds:[<globalFieldNextModuleID>],8
// mov word ptr ds:[<MenuState>],0
// xor esi,esi
// push esi
// call ff8_en.4B7C70
// add esp,4
// inc esi
// cmp esi,2
// jl ff8_en.5226AB
// push 0
// call <ff8_en.ShowCountdownTimer>
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,4
// cmp dword ptr ds:[eax+6C],FFFFFFFF
// jne ff8_en.5226D9
// push 0
// call ff8_en.46B800
// add esp,4
// call ff8_en.46C050
// mov ecx,dword ptr ds:[1CDC6EC]
// push ecx
// push 46
// push 0
// call ff8_en.52CD10
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C9]
// mov byte ptr ds:[1CFF6E9],al
// call <ff8_en.WM2Field_MusicAKAO>
// push eax
// call <ff8_en.PlayMusic_SdMusicPlay>
// push 7F
// push 0
// mov word ptr ds:[1CD8FC4],ax
// call ff8_en.46BB40
// call ff8_en.46C020
// call <ff8_en.InitializeSound_CAL>
// push 7F
// call ff8_en.46B420
// add esp,1C
// mov eax,1
// pop esi
// ret 
// cmp byte ptr ds:[1DCD7B4],3
// jne ff8_en.52274E
// mov dword ptr ds:[esi+144],FFFFFFFF
// mov eax,2
// pop esi
// ret 
// mov ecx,dword ptr ds:[1DCD7B4]
// mov eax,2
// and ecx,FF
// mov dword ptr ds:[esi+144],ecx
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,14
// push ebx
// push ebp
// push esi
// push edi
// mov edi,dword ptr ss:[esp+28]
// movsx eax,byte ptr ds:[edi+184]
// mov eax,dword ptr ds:[edi+eax*4]
// dec eax
// push eax
// mov dword ptr ss:[esp+14],eax
// call <ff8_en.GetDrawPointMagic>
// mov cl,byte ptr ds:[edi+174]
// mov edx,1
// shl edx,cl
// mov bl,al
// mov al,byte ptr ds:[edi+175]
// add esp,4
// xor ebp,ebp
// mov byte ptr ss:[esp+18],bl
// test al,dl
// je ff8_en.5227B9
// mov word ptr ds:[edi+204],bp
// movsx eax,word ptr ds:[edi+204]
// cmp eax,7
// ja ff8_en.522C8A
// jmp dword ptr ds:[eax*4+52300C]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,byte ptr ss:[esp+10]
// push 1000
// push 6
// mov byte ptr ds:[ecx+F2],dl
// call <ff8_en.sub_49FA40>
// push 6
// push 6
// call ff8_en.4A0700
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,10
// mov ecx,dword ptr ds:[eax+68]
// test ch,8
// je ff8_en.522812
// mov al,byte ptr ds:[eax+F3]
// mov byte ptr ds:[1CFF6E8],al
// jmp ff8_en.522819
// mov byte ptr ds:[1CFF6E8],0
// call <ff8_en.sub_495EF0>
// xor ecx,ecx
// mov eax,ff8_en.1CFF1C6
// cmp byte ptr ds:[ecx+<SG_PARTY_BATTLE1>],FF
// je ff8_en.522837
// test byte ptr ds:[eax],2
// jne ff8_en.522969
// add eax,1D0
// inc ecx
// cmp eax,ff8_en.1CFF736
// jl ff8_en.522825
// mov edx,dword ptr ds:[B92324]
// push 7
// push edx
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.52286B
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522860
// mov al,byte ptr ds:[eax]
// mov byte ptr ds:[edx],al
// push ff8_en.1D9CECC
// push 6
// call ff8_en.4A0410
// push ff8_en.1D9CECC
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+10]
// shr eax,10
// add eax,11
// mov word ptr ss:[esp+2C],cx
// mov si,ax
// movsx eax,cx
// cdq 
// sub eax,edx
// mov ecx,A0
// sar eax,1
// sub ecx,eax
// mov word ptr ss:[esp+2E],si
// movsx eax,si
// cdq 
// sub eax,edx
// mov edx,70
// sar eax,1
// sub edx,eax
// lea eax,dword ptr ss:[esp+28]
// push eax
// push 6
// mov word ptr ss:[esp+30],cx
// mov word ptr ss:[esp+32],dx
// call ff8_en.4A07A0
// push 6
// call ff8_en.4A0620
// push 6
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// and bl,80
// mov cl,byte ptr ds:[eax+D3]
// or cl,40
// neg bl
// sbb ebx,ebx
// mov byte ptr ds:[eax+D3],cl
// mov ecx,dword ptr ss:[esp+2C]
// and ebx,A
// add ebx,A
// push ecx
// mov word ptr ds:[1D9CDF4],bx
// call <ff8_en.GetDrawPointStatus>
// add esp,20
// cmp eax,1
// jne ff8_en.522929
// movsx eax,word ptr ds:[1D9CDF4]
// cdq 
// sub eax,edx
// sar eax,1
// mov word ptr ds:[1D9CDF4],ax
// call ff8_en.52D210
// movsx edx,word ptr ds:[1D9CDF4]
// and eax,FF
// add eax,80
// imul eax,edx
// cdq 
// and edx,1FF
// add eax,edx
// sar eax,9
// inc eax
// inc word ptr ds:[edi+204]
// pop edi
// pop esi
// mov word ptr ds:[1D9CDF4],ax
// pop ebp
// mov eax,1
// pop ebx
// add esp,14
// ret 
// mov ecx,dword ptr ss:[esp+10]
// push ecx
// call <ff8_en.GetDrawPointStatus>
// add esp,4
// cmp eax,3
// je ff8_en.5229F7
// mov edx,dword ptr ss:[esp+10]
// push edx
// call <ff8_en.GetDrawPointStatus>
// add esp,4
// cmp eax,2
// je ff8_en.5229F7
// mov eax,dword ptr ds:[B92324]
// push 2
// push eax
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.5229B3
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.5229A8
// mov cl,byte ptr ds:[eax]
// mov eax,ff8_en.1D9CECC
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[1D9CECC]
// test cl,cl
// je ff8_en.5229E0
// cmp byte ptr ds:[eax],C
// jne ff8_en.5229D8
// mov cl,byte ptr ds:[eax+1]
// inc eax
// mov dl,bl
// and dl,3F
// add cl,dl
// mov byte ptr ds:[eax],cl
// mov cl,byte ptr ds:[eax+1]
// inc eax
// test cl,cl
// jne ff8_en.5229C6
// push 7F
// push 80
// push ebp
// push 42
// call <ff8_en.PlayWorldSound>
// add esp,10
// jmp ff8_en.52286F
// mov eax,dword ptr ds:[B92324]
// push 3
// push eax
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.522A1D
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522A12
// mov cl,byte ptr ds:[eax]
// mov byte ptr ds:[edx],cl
// jmp ff8_en.52286F
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[eax+D3],40
// jne ff8_en.522C8A
// mov esi,dword ptr ss:[esp+10]
// push esi
// call <ff8_en.GetDrawPointStatus>
// add esp,4
// cmp eax,3
// je ff8_en.522AA5
// push esi
// call <ff8_en.GetDrawPointStatus>
// add esp,4
// cmp eax,2
// je ff8_en.522AA5
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// test ch,8
// je ff8_en.522A73
// mov cl,byte ptr ds:[eax+F3]
// mov byte ptr ds:[1CFF6E8],cl
// jmp ff8_en.522A7A
// mov byte ptr ds:[1CFF6E8],0
// call <ff8_en.sub_495EF0>
// xor ecx,ecx
// mov eax,ff8_en.1CFF1C6
// cmp byte ptr ds:[ecx+<SG_PARTY_BATTLE1>],FF
// je ff8_en.522A98
// test byte ptr ds:[eax],2
// jne ff8_en.522C83
// add eax,1D0
// inc ecx
// cmp eax,ff8_en.1CFF736
// jl ff8_en.522A86
// mov dword ptr ds:[edi+140],ebp
// jmp ff8_en.522FF1
// xor al,al
// mov byte ptr ds:[1D9CF38],al
// movsx edx,al
// cmp byte ptr ds:[edx+<SG_PARTY_FIELD1>],FF
// je ff8_en.522AC9
// inc al
// cmp al,3
// jl ff8_en.522AB7
// mov byte ptr ds:[1D9CF38],al
// mov eax,dword ptr ds:[B92324]
// push 4
// push eax
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.522AF4
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522AE9
// mov cl,byte ptr ds:[eax]
// and ebx,3F
// mov byte ptr ds:[edx],cl
// mov al,byte ptr ds:[1D9CECC]
// movsx edx,byte ptr ds:[1D9CF38]
// test al,al
// mov dword ptr ss:[esp+18],edx
// mov esi,ff8_en.1D9CECC
// mov dword ptr ss:[esp+10],ebp
// je ff8_en.522BE0
// mov ebp,<ff8_en.SG_PARTY_FIELD1>
// xor eax,eax
// mov al,byte ptr ds:[esi]
// sub eax,2
// je ff8_en.522BB9
// dec eax
// je ff8_en.522B85
// sub eax,3
// jne ff8_en.522BCB
// mov al,byte ptr ss:[ebp]
// push eax
// call ff8_en.52CC50
// mov byte ptr ss:[esp+18],al
// xor ecx,ecx
// mov edi,dword ptr ss:[esp+18]
// push ebx
// and edi,FF
// mov cl,byte ptr ds:[edi+<SG_PARTY_BATTLE1>]
// push ecx
// call <ff8_en.CanStoreMagic>
// add esp,C
// test eax,eax
// jne ff8_en.522BCB
// lea edx,dword ptr ds:[edi*8]
// sub edx,edi
// lea eax,dword ptr ds:[edi+edx*4]
// shl eax,4
// test byte ptr ds:[eax+1CFF1C6],2
// je ff8_en.522BCB
// inc esi
// mov byte ptr ds:[esi],27
// jmp ff8_en.522BCB
// mov al,byte ptr ss:[ebp]
// mov dl,byte ptr ds:[esi+1]
// inc esi
// add dl,al
// push ebx
// push eax
// mov byte ptr ds:[esi],dl
// call ff8_en.52CC50
// add esp,4
// and eax,FF
// push eax
// call <ff8_en.IsMagicJunctioned>
// add esp,8
// test eax,eax
// je ff8_en.522BB6
// add esi,2
// mov byte ptr ds:[esi],5
// inc esi
// mov byte ptr ds:[esi],41
// inc ebp
// jmp ff8_en.522BCB
// mov ecx,dword ptr ss:[esp+18]
// mov eax,dword ptr ss:[esp+10]
// inc ecx
// cmp eax,ecx
// jge ff8_en.522BDD
// inc eax
// mov dword ptr ss:[esp+10],eax
// mov al,byte ptr ds:[esi+1]
// mov edi,dword ptr ss:[esp+28]
// inc esi
// test al,al
// jne ff8_en.522B21
// jmp ff8_en.522BE0
// mov byte ptr ds:[esi],0
// push ff8_en.1D9CECC
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+30]
// shr eax,10
// add eax,11
// mov word ptr ss:[esp+24],cx
// mov si,ax
// movsx eax,cx
// cdq 
// sub eax,edx
// mov edx,A0
// sar eax,1
// sub edx,eax
// mov ecx,70
// movsx eax,si
// mov word ptr ss:[esp+20],dx
// mov word ptr ss:[esp+26],si
// cdq 
// sub eax,edx
// lea edx,dword ptr ss:[esp+20]
// sar eax,1
// sub ecx,eax
// push edx
// push 6
// mov word ptr ss:[esp+2A],cx
// call ff8_en.4A07A0
// movsx eax,byte ptr ds:[1D9CF38]
// push 1
// inc eax
// push 2
// push eax
// push 1
// push ff8_en.1D9CECC
// push 6
// call ff8_en.4A04E0
// push 6
// call ff8_en.4A0620
// push 6
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,40
// add esp,2C
// mov bl,byte ptr ds:[eax+D3]
// or bl,cl
// mov byte ptr ds:[eax+D3],bl
// mov dl,byte ptr ds:[eax+D2]
// or dl,cl
// mov byte ptr ds:[eax+D2],dl
// inc word ptr ds:[edi+204]
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// add esp,14
// ret 
// push 6
// call ff8_en.49FD50
// push 6
// call ff8_en.49FD70
// add esp,8
// mov byte ptr ds:[1D9CDF2],al
// test al,al
// jl ff8_en.522C8A
// push 6
// call ff8_en.4A0660
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,4
// mov cl,byte ptr ds:[eax+D2]
// and cl,BF
// mov byte ptr ds:[eax+D2],cl
// mov al,byte ptr ds:[1D9CDF2]
// test al,al
// jne ff8_en.522CE3
// mov dword ptr ds:[edi+140],ebp
// jmp ff8_en.522FF1
// mov cl,byte ptr ds:[1D9CDF2]
// mov eax,1
// dec cl
// inc word ptr ds:[edi+204]
// pop edi
// pop esi
// pop ebp
// mov byte ptr ds:[1D9CDF2],cl
// pop ebx
// add esp,14
// ret 
// movsx ecx,byte ptr ds:[1D9CDF2]
// mov dl,byte ptr ds:[ecx+<SG_PARTY_FIELD1>]
// push edx
// call ff8_en.52CC50
// push 6
// mov byte ptr ds:[1D9CDD4],al
// call ff8_en.49FBF0
// add esp,8
// test eax,eax
// jne ff8_en.522C8A
// movsx eax,byte ptr ds:[1D9CDD4]
// lea ecx,dword ptr ds:[eax*8]
// sub ecx,eax
// lea edx,dword ptr ds:[eax+ecx*4]
// shl edx,4
// test byte ptr ds:[edx+1CFF1C6],2
// je ff8_en.522D90
// movsx eax,byte ptr ds:[1D9CDF2]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// movzx dx,byte ptr ds:[eax+ecx+C2]
// push edx
// call ff8_en.4747B0
// push 7F
// push 80
// push ebp
// push 43
// call <ff8_en.PlayWorldSound>
// add esp,14
// inc word ptr ds:[edi+204]
// mov eax,1
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,14
// ret 
// add word ptr ds:[edi+204],2
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// add esp,14
// ret 
// call ff8_en.474AA0
// test eax,eax
// jne ff8_en.522C8A
// inc word ptr ds:[edi+204]
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// add esp,14
// ret 
// movsx eax,byte ptr ds:[1D9CDD4]
// lea ecx,dword ptr ds:[eax*8]
// sub ecx,eax
// lea edx,dword ptr ds:[eax+ecx*4]
// shl edx,4
// test byte ptr ds:[edx+1CFF1C6],2
// je ff8_en.522E98
// xor esi,esi
// cmp word ptr ds:[1D9CDF4],bp
// jle ff8_en.522E24
// mov edi,dword ptr ss:[esp+18]
// and edi,3F
// movsx eax,byte ptr ds:[1D9CDD4]
// xor ecx,ecx
// push edi
// mov cl,byte ptr ds:[eax+<SG_PARTY_BATTLE1>]
// push ecx
// call <ff8_en.MagicCountingRelated>
// add esp,8
// test eax,eax
// jne ff8_en.522E24
// movsx edx,word ptr ds:[1D9CDF4]
// inc esi
// cmp esi,edx
// jl ff8_en.522DFB
// push esi
// push 7
// call ff8_en.4A0850
// add esp,8
// test esi,esi
// jne ff8_en.522E6C
// mov eax,dword ptr ds:[B92324]
// push 6
// push eax
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.522E59
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522E4E
// mov cl,byte ptr ds:[eax]
// mov byte ptr ds:[edx],cl
// mov edx,dword ptr ss:[esp+28]
// mov word ptr ds:[edx+204],0
// jmp ff8_en.522ECA
// mov eax,dword ptr ds:[B92324]
// push 5
// push eax
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.522E92
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522E87
// mov cl,byte ptr ds:[eax]
// mov byte ptr ds:[edx],cl
// jmp ff8_en.522ECA
// mov edx,dword ptr ds:[B92324]
// push 6
// push edx
// call <ff8_en.sub_530750>
// mov cl,byte ptr ds:[eax]
// add esp,8
// test cl,cl
// mov edx,ff8_en.1D9CECC
// je ff8_en.522EBF
// mov byte ptr ds:[edx],cl
// mov cl,byte ptr ds:[eax+1]
// inc edx
// inc eax
// test cl,cl
// jne ff8_en.522EB4
// mov al,byte ptr ds:[eax]
// mov word ptr ds:[edi+204],bp
// mov byte ptr ds:[edx],al
// movsx ecx,byte ptr ds:[1D9CDF2]
// mov dl,byte ptr ds:[1D9CECC]
// mov eax,ff8_en.1D9CECC
// mov cl,byte ptr ds:[ecx+<SG_PARTY_FIELD1>]
// test dl,dl
// je ff8_en.522EFB
// cmp byte ptr ds:[eax],3
// jne ff8_en.522EF3
// mov dl,byte ptr ds:[eax+1]
// inc eax
// add dl,cl
// mov byte ptr ds:[eax],dl
// mov dl,byte ptr ds:[eax+1]
// inc eax
// test dl,dl
// jne ff8_en.522EE6
// mov cl,byte ptr ds:[1D9CECC]
// mov eax,ff8_en.1D9CECC
// test cl,cl
// je ff8_en.522F24
// cmp byte ptr ds:[eax],C
// jne ff8_en.522F1C
// mov cl,byte ptr ds:[eax+1]
// inc eax
// mov dl,bl
// and dl,3F
// add cl,dl
// mov byte ptr ds:[eax],cl
// mov cl,byte ptr ds:[eax+1]
// inc eax
// test cl,cl
// jne ff8_en.522F0A
// push ff8_en.1D9CECC
// push 6
// call ff8_en.4A0410
// push ff8_en.1D9CECC
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+10]
// shr eax,10
// add eax,11
// mov word ptr ss:[esp+2C],cx
// mov si,ax
// movsx eax,cx
// cdq 
// sub eax,edx
// mov ecx,A0
// sar eax,1
// sub ecx,eax
// mov word ptr ss:[esp+2E],si
// movsx eax,si
// cdq 
// sub eax,edx
// mov edx,70
// sar eax,1
// sub edx,eax
// lea eax,dword ptr ss:[esp+28]
// push eax
// push 6
// mov word ptr ss:[esp+30],cx
// mov word ptr ss:[esp+32],dx
// call ff8_en.4A07A0
// push 6
// call ff8_en.4A0620
// push 6
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// add esp,1C
// mov dl,byte ptr ds:[eax+D3]
// pop edi
// or dl,40
// pop esi
// mov byte ptr ds:[eax+D3],dl
// mov eax,dword ptr ss:[esp+20]
// pop ebp
// pop ebx
// inc word ptr ds:[eax+204]
// mov eax,1
// add esp,14
// ret 
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,40
// test byte ptr ds:[edx+D3],cl
// jne ff8_en.522C8A
// test cl,bl
// je ff8_en.522FE2
// mov eax,dword ptr ss:[esp+10]
// push 2
// push eax
// jmp ff8_en.522FE9
// mov ecx,dword ptr ss:[esp+10]
// push 3
// push ecx
// call ff8_en.52D190
// add esp,8
// mov al,byte ptr ds:[edi+184]
// dec al
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// add esp,14
// ret 
// dd 5227D0
// dd 522A26
// dd 522AB0
// dd 522C97
// dd 522D05
// dd 522DA5
// dd 522DC6
// dd 522FC1
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov byte ptr ds:[esi+F0],1
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov ecx,dword ptr ds:[eax+198]
// mov byte ptr ds:[esi+F1],dl
// mov edx,dword ptr ds:[eax+194]
// mov eax,dword ptr ds:[eax+190]
// push ecx
// push edx
// push eax
// call ff8_en.474750
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// xor ecx,ecx
// xor edx,edx
// mov cl,byte ptr ds:[eax+F1]
// mov dl,byte ptr ds:[eax+58]
// or ecx,edx
// push ecx
// call <ff8_en.Script_SetDrawPoint>
// add esp,10
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov al,dl
// mov byte ptr ds:[esi+F2],dl
// dec al
// mov byte ptr ds:[esi+F2],al
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,F
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// mov byte ptr ds:[edx+1CE48F0],1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,F
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// mov byte ptr ds:[edx+1CE48F0],0
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// mov dl,byte ptr ds:[ecx+256]
// movsx esi,al
// or dl,80
// mov esi,dword ptr ds:[ecx+esi*4]
// and esi,F
// dec al
// mov byte ptr ds:[ecx+184],al
// mov eax,2
// mov byte ptr ds:[esi+1CE48F0],dl
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// test edx,edx
// je ff8_en.5231A7
// call <ff8_en.SETWITCH>
// mov eax,2
// ret 
// call ff8_en.56DAB0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// call <ff8_en.SETODIN>
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5231F4
// mov word ptr ds:[eax+204],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CFDC5C],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[esi+B6],dx
// mov word ptr ds:[1CFF6E2],dx
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[eax+68],20
// je ff8_en.523294
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// add cl,FE
// mov byte ptr ds:[eax+184],cl
// mov eax,3
// ret 
// mov al,byte ptr ds:[<globalFieldNextModuleID>]
// test al,al
// jne ff8_en.5232A4
// mov byte ptr ds:[<globalFieldNextModuleID>],3
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CFF6E2],dx
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[<MenuState>],dx
// mov eax,3
// ret 
// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// mov al,byte ptr ds:[<battle_result>]
// mov dword ptr ds:[ecx+140],eax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov eax,dword ptr ds:[ecx+68]
// test al,20
// jne ff8_en.52332A
// mov dl,byte ptr ds:[<isMusicLoaded>]
// test dl,dl
// je ff8_en.523323
// or ah,4
// mov dword ptr ds:[ecx+68],eax
// mov eax,2
// ret 
// mov byte ptr ds:[ecx+CF],0
// mov eax,2
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[eax+68]
// and ch,FB
// mov dword ptr ds:[eax+68],ecx
// mov byte ptr ds:[eax+CF],1
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[eax+CF],1
// mov ecx,dword ptr ds:[eax+68]
// or ecx,20
// mov dword ptr ds:[eax+68],ecx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[<globalFieldNextModuleID>],4
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov al,dl
// mov byte ptr ds:[esi+CC],dl
// mov cl,al
// and eax,FF
// dec cl
// push eax
// mov byte ptr ds:[1CFDCA0],cl
// call <ff8_en.nullsub_2>
// add esp,4
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,dx
// mov word ptr ds:[eax+1FE],dx
// mov word ptr ds:[eax+200],cx
// mov eax,2
// ret 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// xor ebx,ebx
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.52359F
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+23C],1
// movsx edx,al
// mov word ptr ds:[esi+21E],bx
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov word ptr ds:[esi+21A],cx
// mov ecx,dword ptr ds:[esi+edx*4]
// shl ecx,C
// dec al
// mov dword ptr ds:[esi+1BC],ecx
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+edx*4]
// shl ecx,C
// dec al
// mov dword ptr ds:[esi+1B8],ecx
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+edx*4]
// mov dx,word ptr ds:[esi+200]
// shl ecx,C
// mov dword ptr ds:[esi+1B4],ecx
// dec al
// movsx ecx,word ptr ds:[1CE476A]
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+1FE],dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// movsx edx,dx
// lea eax,dword ptr ds:[eax+eax*2]
// lea ecx,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[ecx+ecx*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.52350F
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.523587
// movzx ax,al
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// add esp,10
// jmp ff8_en.523543
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.523587
// movzx ax,al
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// add esp,10
// xor eax,eax
// mov byte ptr ds:[esi+24E],dl
// mov al,byte ptr ds:[esi+256]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov word ptr ds:[esi+206],bx
// mov eax,dword ptr ds:[eax*4+1DCB340]
// or dh,20
// mov word ptr ds:[esi+20A],bx
// mov dword ptr ds:[esi+160],edx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bx
// mov word ptr ds:[esi+20C],cx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],bx
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523636
// test dword ptr ds:[esi+160],40000
// je ff8_en.523628
// movzx ax,byte ptr ds:[esi+24F]
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],dl
// mov edx,dword ptr ds:[esi+160]
// add esp,10
// mov eax,dword ptr ds:[eax*4+1DCB340]
// and edx,FFFB27FF
// or dh,20
// mov word ptr ds:[esi+206],bx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[esi+20A],bx
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],bx
// mov dword ptr ds:[esi+160],edx
// mov byte ptr ds:[esi+240],bl
// pop esi
// mov eax,2
// pop ebx
// ret 
// pop esi
// mov eax,1
// pop ebx
// ret 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// push edi
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.52377F
// mov al,byte ptr ds:[esi+184]
// xor edi,edi
// movsx edx,al
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],di
// mov cx,word ptr ds:[esi+edx*4]
// dec al
// mov word ptr ds:[esi+21A],cx
// mov byte ptr ds:[esi+184],al
// movsx ecx,word ptr ds:[1CE476A]
// mov dx,word ptr ds:[esi+200]
// lea eax,dword ptr ds:[ecx+ecx*8]
// mov word ptr ds:[esi+1FE],dx
// shl eax,6
// sub eax,ecx
// movsx edx,dx
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.523738
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.523765
// xor bx,bx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov bl,al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// jmp ff8_en.523765
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.523765
// movzx ax,al
// push eax
// push esi
// call ff8_en.526320
// mov eax,dword ptr ds:[esi+160]
// add esp,8
// or ah,20
// mov dword ptr ds:[esi+160],eax
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],di
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// jmp ff8_en.523781
// xor edi,edi
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523820
// test dword ptr ds:[esi+160],40000
// je ff8_en.523802
// movzx bx,byte ptr ds:[esi+24F]
// movsx ecx,bx
// xor edx,edx
// push edi
// mov dl,byte ptr ds:[esi+256]
// push ecx
// push D
// push edx
// call ff8_en.532890
// mov edx,dword ptr ds:[esi+160]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// and edx,FFFB27FF
// add esp,10
// or dh,20
// mov eax,dword ptr ds:[eax*4+1DCB340]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+240],0
// dec al
// pop edi
// mov byte ptr ds:[esi+184],al
// pop esi
// mov eax,2
// pop ebx
// ret 
// movsx eax,byte ptr ds:[esi+184]
// mov ecx,dword ptr ds:[esi+eax*4]
// pop edi
// lea eax,dword ptr ds:[esi+eax*4]
// mov edx,dword ptr ds:[ecx*4+1D9D020]
// mov ecx,dword ptr ds:[edx+190]
// mov dword ptr ds:[esi+1B4],ecx
// mov edx,dword ptr ds:[eax]
// mov ecx,dword ptr ds:[edx*4+1D9D020]
// mov edx,dword ptr ds:[ecx+194]
// mov dword ptr ds:[esi+1B8],edx
// mov eax,dword ptr ds:[eax]
// mov ecx,dword ptr ds:[eax*4+1D9D020]
// mov eax,1
// mov edx,dword ptr ds:[ecx+198]
// mov dword ptr ds:[esi+1BC],edx
// pop esi
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// xor ebx,ebx
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.5239CA
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+23C],1
// movsx edx,al
// mov word ptr ds:[esi+21E],bx
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+21A],cx
// mov dx,word ptr ds:[esi+200]
// movsx ecx,word ptr ds:[1CE476A]
// mov word ptr ds:[esi+1FE],dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// movsx edx,dx
// lea eax,dword ptr ds:[eax+eax*2]
// lea ecx,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[ecx+ecx*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.52393A
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.5239B2
// movzx ax,al
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// add esp,10
// jmp ff8_en.52396E
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.5239B2
// movzx ax,al
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// add esp,10
// xor eax,eax
// mov byte ptr ds:[esi+24E],dl
// mov al,byte ptr ds:[esi+256]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov word ptr ds:[esi+206],bx
// mov eax,dword ptr ds:[eax*4+1DCB340]
// or dh,20
// mov word ptr ds:[esi+20A],bx
// mov dword ptr ds:[esi+160],edx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bx
// mov word ptr ds:[esi+20C],cx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],bx
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523A6F
// test dword ptr ds:[esi+160],40000
// je ff8_en.523A53
// movzx ax,byte ptr ds:[esi+24F]
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],dl
// mov edx,dword ptr ds:[esi+160]
// add esp,10
// mov eax,dword ptr ds:[eax*4+1DCB340]
// and edx,FFFB27FF
// or dh,20
// mov word ptr ds:[esi+206],bx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[esi+20A],bx
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],bx
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+240],bl
// dec al
// mov byte ptr ds:[esi+184],al
// pop esi
// mov eax,2
// pop ebx
// ret 
// movsx eax,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov ecx,dword ptr ds:[esi+eax*4]
// xor eax,eax
// mov al,byte ptr ds:[ecx+edx+C2]
// lea ecx,dword ptr ds:[eax+eax*4]
// lea ecx,dword ptr ds:[ecx+ecx*4]
// lea eax,dword ptr ds:[eax+ecx*2]
// lea edx,dword ptr ds:[eax+eax*2]
// mov eax,dword ptr ds:[<entity_other>]
// mov ecx,dword ptr ds:[eax+edx*4+190]
// lea eax,dword ptr ds:[eax+edx*4]
// mov dword ptr ds:[esi+1B4],ecx
// mov edx,dword ptr ds:[eax+194]
// mov eax,dword ptr ds:[eax+198]
// mov dword ptr ds:[esi+1B8],edx
// mov dword ptr ds:[esi+1BC],eax
// pop esi
// mov eax,1
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// mov edx,eax
// xor ebx,ebx
// mov cl,byte ptr ds:[esi+174]
// shl edx,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,dl
// je ff8_en.523B84
// mov cl,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+23C],al
// movsx edx,cl
// mov word ptr ds:[esi+21E],bx
// dec cl
// mov dx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],cl
// mov word ptr ds:[esi+21A],dx
// mov dx,word ptr ds:[esi+200]
// mov word ptr ds:[esi+1FE],dx
// movsx edx,cl
// mov edx,dword ptr ds:[esi+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[esi+1BC],edx
// movsx edx,cl
// mov byte ptr ds:[esi+184],cl
// mov edx,dword ptr ds:[esi+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[esi+1B8],edx
// movsx edx,cl
// mov byte ptr ds:[esi+184],cl
// mov edx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+262],bl
// shl edx,C
// dec cl
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],cl
// mov byte ptr ds:[esi+240],al
// mov word ptr ds:[esi+1DA],bx
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523C18
// test dword ptr ds:[esi+160],40000
// je ff8_en.523C0D
// movzx ax,byte ptr ds:[esi+24F]
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],dl
// mov edx,dword ptr ds:[esi+160]
// add esp,10
// mov eax,dword ptr ds:[eax*4+1DCB340]
// and edx,FFFB27FF
// or dh,20
// mov word ptr ds:[esi+206],bx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[esi+20A],bx
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],bx
// mov dword ptr ds:[esi+160],edx
// mov byte ptr ds:[esi+240],bl
// mov eax,2
// pop esi
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// xor ebx,ebx
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.523CC7
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+23C],1
// movsx edx,al
// mov word ptr ds:[esi+21E],bx
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov dx,word ptr ds:[esi+200]
// mov word ptr ds:[esi+21A],cx
// mov byte ptr ds:[esi+184],al
// movsx ecx,al
// mov word ptr ds:[esi+1FE],dx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1BC],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B8],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// mov word ptr ds:[esi+1DA],bx
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],al
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523D5E
// test dword ptr ds:[esi+160],40000
// je ff8_en.523D50
// movzx ax,byte ptr ds:[esi+24F]
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],dl
// mov edx,dword ptr ds:[esi+160]
// add esp,10
// mov eax,dword ptr ds:[eax*4+1DCB340]
// and edx,FFFB27FF
// or dh,20
// mov word ptr ds:[esi+206],bx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[esi+20A],bx
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],bx
// mov dword ptr ds:[esi+160],edx
// mov byte ptr ds:[esi+240],bl
// pop esi
// mov eax,2
// pop ebx
// ret 
// pop esi
// mov eax,1
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// push edi
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.523DD0
// mov al,byte ptr ds:[esi+184]
// xor edi,edi
// movsx edx,al
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],di
// mov cx,word ptr ds:[esi+edx*4]
// mov dx,word ptr ds:[esi+200]
// dec al
// mov word ptr ds:[esi+21A],cx
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+1FE],dx
// mov word ptr ds:[esi+1DA],di
// jmp ff8_en.523DD2
// xor edi,edi
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523E72
// test dword ptr ds:[esi+160],40000
// je ff8_en.523E55
// push ebx
// xor ecx,ecx
// movzx bx,byte ptr ds:[esi+24F]
// mov cl,byte ptr ds:[esi+256]
// push edi
// movsx eax,bx
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and edx,FFFB27FF
// pop ebx
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+240],0
// dec al
// pop edi
// mov byte ptr ds:[esi+184],al
// mov eax,2
// pop esi
// ret 
// movsx eax,byte ptr ds:[esi+184]
// mov ecx,dword ptr ds:[esi+eax*4]
// pop edi
// lea eax,dword ptr ds:[esi+eax*4]
// mov edx,dword ptr ds:[ecx*4+1D9D020]
// mov ecx,dword ptr ds:[edx+190]
// mov dword ptr ds:[esi+1B4],ecx
// mov edx,dword ptr ds:[eax]
// mov ecx,dword ptr ds:[edx*4+1D9D020]
// mov edx,dword ptr ds:[ecx+194]
// mov dword ptr ds:[esi+1B8],edx
// mov eax,dword ptr ds:[eax]
// mov ecx,dword ptr ds:[eax*4+1D9D020]
// mov eax,1
// mov edx,dword ptr ds:[ecx+198]
// mov dword ptr ds:[esi+1BC],edx
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// push edi
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.523F30
// mov al,byte ptr ds:[esi+184]
// xor edi,edi
// movsx edx,al
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],di
// mov cx,word ptr ds:[esi+edx*4]
// mov dx,word ptr ds:[esi+200]
// dec al
// mov word ptr ds:[esi+21A],cx
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+1FE],dx
// mov word ptr ds:[esi+1DA],di
// jmp ff8_en.523F32
// xor edi,edi
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.523FD2
// test dword ptr ds:[esi+160],40000
// je ff8_en.523FB5
// push ebx
// xor ecx,ecx
// movzx bx,byte ptr ds:[esi+24F]
// mov cl,byte ptr ds:[esi+256]
// push edi
// movsx eax,bx
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and edx,FFFB27FF
// pop ebx
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov byte ptr ds:[esi+240],0
// dec al
// pop edi
// mov byte ptr ds:[esi+184],al
// mov eax,2
// pop esi
// ret 
// movsx eax,byte ptr ds:[esi+184]
// xor edx,edx
// pop edi
// mov ecx,dword ptr ds:[esi+eax*4]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,byte ptr ds:[ecx+eax+C2]
// mov ecx,edx
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+ecx*4]
// mov ecx,dword ptr ds:[edx+ecx*4+190]
// mov edx,dword ptr ds:[eax+194]
// mov eax,dword ptr ds:[eax+198]
// mov dword ptr ds:[esi+1B4],ecx
// mov dword ptr ds:[esi+1B8],edx
// mov dword ptr ds:[esi+1BC],eax
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// push edi
// xor edi,edi
// mov al,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[esi+160]
// movsx ecx,al
// or edx,20000
// mov byte ptr ds:[esi+23C],1
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[esi+21E],di
// mov dx,word ptr ds:[esi+ecx*4]
// dec al
// movsx ecx,al
// mov word ptr ds:[esi+21A],dx
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1BC],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B8],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// movsx ecx,word ptr ds:[1CE476A]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],al
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// mov dx,word ptr ds:[esi+200]
// sub eax,ecx
// mov word ptr ds:[esi+1FE],dx
// lea eax,dword ptr ds:[eax+eax*2]
// movsx edx,dx
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.5240FF
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.524170
// jmp ff8_en.52410F
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.524170
// xor bx,bx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov bl,al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],di
// or eax,40000
// pop edi
// mov dword ptr ds:[esi+160],eax
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// push edi
// xor edi,edi
// mov al,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[esi+160]
// movsx ecx,al
// or edx,20000
// mov byte ptr ds:[esi+23C],1
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[esi+21E],di
// mov dx,word ptr ds:[esi+ecx*4]
// dec al
// movsx ecx,word ptr ds:[1CE476A]
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+21A],dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// mov dx,word ptr ds:[esi+200]
// shl eax,6
// sub eax,ecx
// mov word ptr ds:[esi+1FE],dx
// movsx edx,dx
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.52422A
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.52429B
// jmp ff8_en.52423A
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.52429B
// xor bx,bx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov bl,al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[esi+160]
// movsx ecx,al
// or edx,40000
// mov word ptr ds:[esi+1DA],di
// lea ecx,dword ptr ds:[esi+ecx*4]
// mov dword ptr ds:[esi+160],edx
// dec al
// pop edi
// mov edx,dword ptr ds:[ecx]
// mov edx,dword ptr ds:[edx*4+1D9D020]
// mov edx,dword ptr ds:[edx+190]
// mov dword ptr ds:[esi+1B4],edx
// mov edx,dword ptr ds:[ecx]
// mov edx,dword ptr ds:[edx*4+1D9D020]
// mov edx,dword ptr ds:[edx+194]
// mov dword ptr ds:[esi+1B8],edx
// mov ecx,dword ptr ds:[ecx]
// mov byte ptr ds:[esi+184],al
// mov eax,3
// mov edx,dword ptr ds:[ecx*4+1D9D020]
// mov ecx,dword ptr ds:[edx+198]
// mov dword ptr ds:[esi+1BC],ecx
// pop esi
// pop ebx
// ret 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// push edi
// xor edi,edi
// mov al,byte ptr ds:[esi+184]
// mov edx,dword ptr ds:[esi+160]
// movsx ecx,al
// or edx,20000
// mov byte ptr ds:[esi+23C],1
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[esi+21E],di
// mov dx,word ptr ds:[esi+ecx*4]
// dec al
// movsx ecx,word ptr ds:[1CE476A]
// mov byte ptr ds:[esi+184],al
// mov word ptr ds:[esi+21A],dx
// lea eax,dword ptr ds:[ecx+ecx*8]
// mov dx,word ptr ds:[esi+200]
// shl eax,6
// sub eax,ecx
// mov word ptr ds:[esi+1FE],dx
// movsx edx,dx
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// cmp edx,ecx
// jl ff8_en.52439A
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.52440B
// jmp ff8_en.5243AA
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.52440B
// xor bx,bx
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov bl,al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov word ptr ds:[eax+52],di
// mov dword ptr ds:[esi+160],edx
// mov al,byte ptr ds:[esi+184]
// mov word ptr ds:[esi+1DA],di
// mov edi,dword ptr ds:[esi+160]
// movsx ecx,al
// or edi,40000
// mov dword ptr ds:[esi+160],edi
// mov edx,dword ptr ds:[esi+ecx*4]
// mov edi,dword ptr ds:[<&SG_FIELD_VARS>]
// xor ecx,ecx
// dec al
// mov cl,byte ptr ds:[edx+edi+C2]
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[<entity_other>]
// pop edi
// lea eax,dword ptr ds:[ecx+ecx*4]
// lea eax,dword ptr ds:[eax+eax*4]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[edx+ecx*4]
// mov ecx,dword ptr ds:[edx+ecx*4+190]
// mov edx,dword ptr ds:[eax+194]
// mov eax,dword ptr ds:[eax+198]
// mov dword ptr ds:[esi+1B4],ecx
// mov dword ptr ds:[esi+1B8],edx
// mov dword ptr ds:[esi+1BC],eax
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// xor edx,edx
// mov ecx,dword ptr ds:[eax+160]
// mov byte ptr ds:[eax+23C],1
// or ecx,20000
// mov word ptr ds:[eax+21E],dx
// mov dword ptr ds:[eax+160],ecx
// mov cl,byte ptr ds:[eax+184]
// movsx esi,cl
// dec cl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+21A],si
// mov si,word ptr ds:[eax+200]
// mov word ptr ds:[eax+1FE],si
// movsx esi,cl
// mov esi,dword ptr ds:[eax+esi*4]
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1BC],esi
// movsx esi,cl
// mov byte ptr ds:[eax+184],cl
// mov esi,dword ptr ds:[eax+esi*4]
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1B8],esi
// movsx esi,cl
// mov byte ptr ds:[eax+184],cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov word ptr ds:[eax+1DA],dx
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1B4],esi
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+262],dl
// mov byte ptr ds:[eax+240],1
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// xor edx,edx
// mov ecx,dword ptr ds:[eax+160]
// mov byte ptr ds:[eax+23C],1
// or ecx,20000
// mov word ptr ds:[eax+21E],dx
// mov dword ptr ds:[eax+160],ecx
// mov cl,byte ptr ds:[eax+184]
// movsx esi,cl
// dec cl
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+21A],si
// mov si,word ptr ds:[eax+200]
// mov word ptr ds:[eax+1FE],si
// movsx esi,cl
// mov esi,dword ptr ds:[eax+esi*4]
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1BC],esi
// movsx esi,cl
// mov byte ptr ds:[eax+184],cl
// mov esi,dword ptr ds:[eax+esi*4]
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1B8],esi
// movsx esi,cl
// mov byte ptr ds:[eax+184],cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov word ptr ds:[eax+1DA],dx
// shl esi,C
// dec cl
// mov dword ptr ds:[eax+1B4],esi
// mov byte ptr ds:[eax+184],cl
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// cmp word ptr ds:[ecx+21E],2
// sete al
// inc eax
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// push edi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov esi,dword ptr ds:[edi*4+1D9D020]
// test dword ptr ds:[esi+160],eax.10000000
// je ff8_en.5246E8
// cmp byte ptr ds:[esi+23C],1
// jne ff8_en.5246E8
// push ebx
// mov byte ptr ds:[esi+23C],0
// movzx bx,byte ptr ds:[esi+24F]
// movsx eax,bx
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// mov byte ptr ds:[esi+24E],bl
// mov dl,byte ptr ds:[esi+256]
// mov ebx,dword ptr ds:[esi+160]
// and bh,7
// add esp,10
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov dword ptr ds:[esi+160],ebx
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],0
// mov eax,dword ptr ds:[edi*4+1D9D020]
// mov word ptr ds:[esi+20C],cx
// pop ebx
// mov edx,dword ptr ds:[eax+160]
// and dh,27
// or dh,20
// mov dword ptr ds:[eax+160],edx
// pop edi
// mov eax,2
// pop esi
// ret 
// mov ecx,dword ptr ss:[esp+4]
// push ebx
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+184]
// xor ebx,ebx
// movsx edx,al
// dec al
// push edi
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov bl,byte ptr ds:[edx+esi+C2]
// mov edx,ebx
// mov eax,edx
// shl eax,4
// add eax,edx
// lea edi,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[<entity_other>]
// shl edi,2
// lea esi,dword ptr ds:[edi+eax]
// mov al,byte ptr ds:[edi+eax+23C]
// cmp al,1
// jne ff8_en.5247C8
// mov byte ptr ds:[esi+23C],0
// xor edx,edx
// movzx bx,byte ptr ds:[esi+24F]
// mov dl,byte ptr ds:[esi+256]
// push 0
// movsx ecx,bx
// push ecx
// push D
// push edx
// call ff8_en.532890
// xor eax,eax
// mov byte ptr ds:[esi+24E],bl
// mov al,byte ptr ds:[esi+256]
// mov ebx,dword ptr ds:[esi+160]
// and bh,7
// mov word ptr ds:[esi+206],0
// mov eax,dword ptr ds:[eax*4+1DCB340]
// mov word ptr ds:[esi+20A],0
// mov dword ptr ds:[esi+160],ebx
// add esp,10
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],0
// mov eax,dword ptr ds:[<entity_other>]
// mov word ptr ds:[esi+20C],cx
// mov edx,dword ptr ds:[edi+eax+160]
// and dh,27
// or dh,20
// mov dword ptr ds:[edi+eax+160],edx
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.524805
// and dword ptr ds:[eax+160],FFFEFFFF
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[ecx+262],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// mov eax,1
// xor ebx,ebx
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.524903
// mov al,byte ptr ds:[esi+184]
// mov dx,word ptr ds:[esi+200]
// movsx ecx,al
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21E],bx
// mov word ptr ds:[esi+1FE],dx
// mov dx,word ptr ds:[esi+ecx*4]
// dec al
// mov word ptr ds:[esi+204],dx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// dec al
// mov dx,word ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// movsx ecx,al
// mov word ptr ds:[esi+21A],dx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1BC],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B8],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+262],bl
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],al
// mov byte ptr ds:[esi+240],1
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.5249A8
// mov ax,word ptr ds:[esi+1FE]
// mov word ptr ds:[esi+202],ax
// mov eax,dword ptr ds:[esi+160]
// test eax,40000
// je ff8_en.52499A
// movzx ax,byte ptr ds:[esi+24F]
// movsx ecx,ax
// xor edx,edx
// push ebx
// mov dl,byte ptr ds:[esi+256]
// push ecx
// push D
// push edx
// mov dword ptr ss:[esp+1C],eax
// call ff8_en.532890
// mov al,byte ptr ss:[esp+1C]
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],al
// add esp,10
// mov word ptr ds:[esi+206],bx
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov word ptr ds:[esi+20A],bx
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// and eax,FFFB27FF
// or ah,20
// mov dword ptr ds:[esi+160],eax
// mov byte ptr ds:[esi+240],bl
// pop esi
// mov eax,2
// pop ebx
// ret 
// movsx ecx,word ptr ds:[esi+1FE]
// movsx edx,word ptr ds:[1CE476A]
// push edi
// mov eax,dword ptr ds:[esi+1B4]
// movsx edi,word ptr ds:[esi+204]
// sub edi,ecx
// imul edi,edx
// sub eax,dword ptr ds:[esi+190]
// cdq 
// and edx,FFF
// add eax,edx
// mov edx,dword ptr ds:[esi+194]
// mov ecx,eax
// mov eax,dword ptr ds:[esi+1B8]
// sub eax,edx
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov edx,eax
// sar ecx,C
// imul edx,eax
// mov eax,ecx
// imul eax,ecx
// add edx,eax
// push edx
// call ff8_en.56BEC0
// add esp,4
// test eax,eax
// jg ff8_en.524A19
// add word ptr ds:[esi+1FE],di
// jmp ff8_en.524A72
// mov eax,dword ptr ds:[esi+1B4]
// mov edx,dword ptr ds:[esi+190]
// sub eax,edx
// cdq 
// and edx,FFF
// add eax,edx
// mov edx,dword ptr ds:[esi+194]
// mov ecx,eax
// mov eax,dword ptr ds:[esi+1B8]
// sub eax,edx
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov edx,eax
// sar ecx,C
// imul edx,eax
// mov eax,ecx
// imul eax,ecx
// add edx,eax
// push edx
// call ff8_en.56BEC0
// mov ecx,eax
// mov eax,edi
// cdq 
// idiv ecx
// add esp,4
// add word ptr ds:[esi+1FE],ax
// movsx ecx,word ptr ds:[1CE476A]
// pop edi
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// lea edx,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+edx*2]
// movsx ecx,word ptr ds:[esi+1FE]
// lea eax,dword ptr ds:[eax+eax*4]
// shl eax,2
// sar eax,9
// cmp ecx,eax
// jl ff8_en.524AF9
// mov al,byte ptr ds:[esi+251]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.524B71
// movzx ax,al
// movsx edx,ax
// mov dword ptr ss:[esp+C],eax
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// push ebx
// push edx
// push D
// push eax
// call ff8_en.532890
// mov cl,byte ptr ss:[esp+1C]
// add esp,10
// xor edx,edx
// mov byte ptr ds:[esi+24E],cl
// mov dl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],bx
// mov word ptr ds:[esi+20A],bx
// mov eax,dword ptr ds:[edx*4+1DCB340]
// jmp ff8_en.524B50
// mov al,byte ptr ds:[esi+250]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.524B71
// movzx ax,al
// mov dword ptr ss:[esp+C],eax
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// push ebx
// movsx eax,ax
// push eax
// push D
// push ecx
// call ff8_en.532890
// mov dl,byte ptr ss:[esp+1C]
// add esp,10
// xor eax,eax
// mov byte ptr ds:[esi+24E],dl
// mov al,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],bx
// mov word ptr ds:[esi+20A],bx
// mov eax,dword ptr ds:[eax*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// mov cx,word ptr ds:[eax+C]
// and dh,27
// mov word ptr ds:[esi+20C],cx
// or dh,20
// mov word ptr ds:[eax+52],bx
// mov dword ptr ds:[esi+160],edx
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+1DA],bx
// or eax,40000
// mov dword ptr ds:[esi+160],eax
// pop esi
// mov eax,1
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push ebp
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov eax,1
// push edi
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.524D81
// mov cl,byte ptr ds:[esi+255]
// xor edi,edi
// xor eax,eax
// cmp byte ptr ds:[eax+<SG_PARTY_FIELD1>],cl
// je ff8_en.524BDB
// inc eax
// cmp eax,3
// jl ff8_en.524BCD
// sub eax,edi
// mov dword ptr ds:[1D9CF44],edi
// mov dword ptr ds:[1D9CF40],edi
// mov dword ptr ds:[1D9CF3C],edi
// je ff8_en.524CA5
// dec eax
// je ff8_en.524C5C
// dec eax
// je ff8_en.524C0C
// push 38A
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// jmp ff8_en.524D10
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C2]
// cmp al,FF
// je ff8_en.524C43
// and eax,FF
// push esi
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[ecx+eax*4]
// push eax
// mov dword ptr ds:[1D9CF3C],eax
// call ff8_en.524F40
// add esp,8
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C3]
// cmp al,FF
// je ff8_en.524D13
// jmp ff8_en.524CEC
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C2]
// cmp al,FF
// je ff8_en.524C93
// and eax,FF
// push esi
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[ecx+eax*4]
// push eax
// mov dword ptr ds:[1D9CF3C],eax
// call ff8_en.524F40
// add esp,8
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C4]
// cmp al,FF
// je ff8_en.524D13
// jmp ff8_en.524CEC
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C3]
// cmp al,FF
// je ff8_en.524CDC
// and eax,FF
// push esi
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[ecx+eax*4]
// push eax
// mov dword ptr ds:[1D9CF3C],eax
// call ff8_en.524F40
// add esp,8
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[edx+C4]
// cmp al,FF
// je ff8_en.524D13
// and eax,FF
// push esi
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[ecx+eax*4]
// push eax
// mov dword ptr ds:[1D9CF40],eax
// call ff8_en.524F40
// add esp,8
// movzx bx,byte ptr ds:[esi+24F]
// movsx edx,bx
// xor eax,eax
// push edi
// mov al,byte ptr ds:[esi+256]
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov byte ptr ds:[esi+24E],bl
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// and ah,27
// pop edi
// or ah,20
// mov dword ptr ds:[esi+160],eax
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// ret 
// mov esi,dword ptr ds:[1D9CF3C]
// xor ebp,ebp
// cmp esi,ebp
// je ff8_en.524E20
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.524E20
// mov al,byte ptr ds:[esi+24F]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.524E20
// xor bx,bx
// lea edi,dword ptr ds:[esi+256]
// mov bl,al
// xor edx,edx
// mov dl,byte ptr ds:[edi]
// push ebp
// movsx ecx,bx
// push ecx
// push D
// push edx
// call ff8_en.532890
// xor eax,eax
// mov byte ptr ds:[esi+24E],bl
// mov al,byte ptr ds:[edi]
// mov word ptr ds:[esi+206],bp
// mov word ptr ds:[esi+20A],bp
// add esp,10
// mov eax,dword ptr ds:[eax*4+1DCB340]
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bp
// mov word ptr ds:[esi+20C],cx
// mov ecx,dword ptr ds:[esi+160]
// and ch,7
// mov dword ptr ds:[esi+160],ecx
// mov esi,dword ptr ds:[1D9CF3C]
// mov eax,dword ptr ds:[esi+160]
// or ah,80
// mov dword ptr ds:[esi+160],eax
// mov eax,dword ptr ds:[1D9CF40]
// cmp eax,ebp
// je ff8_en.524EC3
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.524EC3
// mov cl,byte ptr ds:[eax+24F]
// mov dl,byte ptr ds:[eax+24E]
// cmp dl,cl
// je ff8_en.524EC3
// xor bx,bx
// mov esi,eax
// mov bl,cl
// lea edi,dword ptr ds:[eax+256]
// movsx edx,bx
// xor eax,eax
// push ebp
// mov al,byte ptr ds:[edi]
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[edi]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],bp
// mov word ptr ds:[esi+20A],bp
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bp
// mov eax,dword ptr ds:[1D9CF40]
// mov word ptr ds:[esi+20C],dx
// mov edx,dword ptr ds:[esi+160]
// and dh,7
// mov dword ptr ds:[esi+160],edx
// mov ecx,dword ptr ds:[eax+160]
// mov esi,dword ptr ds:[1D9CF3C]
// or ch,80
// mov dword ptr ds:[eax+160],ecx
// cmp esi,ebp
// je ff8_en.524ED1
// cmp word ptr ds:[esi+21E],2
// jne ff8_en.524EDF
// cmp eax,ebp
// je ff8_en.524EE9
// cmp word ptr ds:[eax+21E],2
// je ff8_en.524EE9
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// ret 
// call ff8_en.47ACE0
// mov eax,dword ptr ds:[1D9CF3C]
// mov ecx,FFFFFFFE
// cmp eax,ebp
// je ff8_en.524F11
// mov edx,dword ptr ds:[eax+160]
// and edx,ecx
// mov dword ptr ds:[eax+160],edx
// mov byte ptr ds:[eax+23C],0
// mov eax,dword ptr ds:[1D9CF40]
// cmp eax,ebp
// je ff8_en.524F2F
// mov edx,dword ptr ds:[eax+160]
// and edx,ecx
// mov dword ptr ds:[eax+160],edx
// mov byte ptr ds:[eax+23C],0
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push ebp
// mov ebp,dword ptr ss:[esp+10]
// push esi
// mov esi,dword ptr ss:[esp+10]
// push edi
// mov eax,dword ptr ss:[ebp+190]
// sub eax,dword ptr ds:[esi+190]
// cdq 
// and edx,FFF
// add eax,edx
// mov edx,dword ptr ds:[esi+194]
// mov ecx,eax
// mov eax,dword ptr ss:[ebp+194]
// sub eax,edx
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov edx,eax
// sar ecx,C
// imul edx,eax
// mov eax,ecx
// imul eax,ecx
// movsx ecx,word ptr ds:[1CE476A]
// add edx,eax
// cmp edx,3F480
// jl ff8_en.524FC4
// mov eax,ecx
// shl eax,7
// sub eax,ecx
// shl eax,3
// sub eax,ecx
// movzx bx,byte ptr ds:[esi+251]
// lea eax,dword ptr ds:[eax+eax*4]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,3
// sar ecx,9
// mov word ptr ds:[esi+1FE],cx
// jmp ff8_en.524FEA
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// movzx bx,byte ptr ds:[esi+250]
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// mov word ptr ds:[esi+1FE],cx
// movsx edx,bx
// xor edi,edi
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// push edi
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov word ptr ds:[esi+21E],di
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov ecx,dword ptr ss:[ebp+190]
// mov dword ptr ds:[esi+1B4],ecx
// mov ecx,dword ptr ss:[ebp+198]
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// mov edx,dword ptr ss:[ebp+194]
// and ah,7
// mov dword ptr ds:[esi+160],eax
// or eax,2001
// mov byte ptr ds:[esi+24E],bl
// mov byte ptr ds:[esi+23C],1
// mov word ptr ds:[esi+21A],60
// mov dword ptr ds:[esi+1B8],edx
// mov dword ptr ds:[esi+1BC],ecx
// mov dword ptr ds:[esi+160],eax
// pop edi
// pop esi
// pop ebp
// pop ebx
// ret 
// sub esp,10
// mov eax,1
// push ebx
// push ebp
// push esi
// mov esi,dword ptr ss:[esp+20]
// push edi
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.5252BE
// mov al,byte ptr ds:[esi+184]
// xor ebx,ebx
// movsx edx,al
// mov dword ptr ds:[1D9CF44],ebx
// mov dword ptr ds:[1D9CF40],ebx
// mov ecx,dword ptr ds:[esi+edx*4]
// mov dword ptr ds:[1D9CF3C],ebx
// shl ecx,C
// dec al
// mov dword ptr ss:[esp+14],ecx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+ecx*4]
// shl ecx,C
// dec al
// mov dword ptr ss:[esp+18],ecx
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+edx*4]
// shl ecx,C
// dec al
// mov dword ptr ss:[esp+1C],ecx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov ebx,dword ptr ds:[esi+ecx*4]
// shl ebx,C
// dec al
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov ebp,dword ptr ds:[esi+edx*4]
// shl ebp,C
// dec al
// mov dword ptr ss:[esp+24],ebp
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+ecx*4]
// shl ecx,C
// dec al
// mov dword ptr ss:[esp+10],ecx
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov ecx,dword ptr ds:[esi+edx*4]
// shl ecx,C
// dec al
// movsx edx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+edx*4]
// shl edx,C
// dec al
// movsx edi,al
// mov byte ptr ds:[esi+184],al
// mov edi,dword ptr ds:[esi+edi*4]
// shl edi,C
// dec al
// mov byte ptr ds:[esi+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[eax+C2]
// cmp al,FF
// je ff8_en.5251DD
// and eax,FF
// push ecx
// mov ebp,eax
// push edx
// shl ebp,4
// add ebp,eax
// push edi
// lea eax,dword ptr ss:[ebp+ebp*8]
// mov ebp,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ss:[ebp+eax*4]
// push eax
// mov dword ptr ds:[1D9CF3C],eax
// call ff8_en.525560
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[esi+256]
// add esp,10
// mov dl,byte ptr ds:[ecx+C2]
// cmp dl,al
// je ff8_en.5251D9
// mov eax,dword ptr ds:[1D9CF3C]
// or dword ptr ds:[eax+160],1
// mov ebp,dword ptr ss:[esp+24]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[eax+C3]
// cmp al,FF
// je ff8_en.52523B
// and eax,FF
// mov edx,dword ptr ds:[<entity_other>]
// mov ecx,eax
// push ebx
// shl eax,4
// add eax,ecx
// push ebp
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+ecx*4]
// mov ecx,dword ptr ss:[esp+18]
// push ecx
// push eax
// mov dword ptr ds:[1D9CF40],eax
// call ff8_en.525560
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[esi+256]
// add esp,10
// mov al,byte ptr ds:[edx+C3]
// cmp al,cl
// je ff8_en.52523B
// mov eax,dword ptr ds:[1D9CF40]
// or dword ptr ds:[eax+160],1
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov al,byte ptr ds:[ecx+C4]
// cmp al,FF
// je ff8_en.5254F8
// and eax,FF
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ss:[esp+14]
// push ecx
// mov ecx,dword ptr ss:[esp+20]
// lea edx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+edx*4]
// mov edx,dword ptr ss:[esp+1C]
// push edx
// push ecx
// push eax
// mov dword ptr ds:[1D9CF44],eax
// call ff8_en.525560
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov cl,byte ptr ds:[esi+256]
// add esp,10
// mov al,byte ptr ds:[edx+C4]
// cmp al,cl
// je ff8_en.5254F8
// mov eax,dword ptr ds:[1D9CF44]
// pop edi
// pop esi
// pop ebp
// mov ecx,dword ptr ds:[eax+160]
// pop ebx
// or ecx,1
// mov dword ptr ds:[eax+160],ecx
// mov eax,1
// add esp,10
// ret 
// mov esi,dword ptr ds:[1D9CF3C]
// xor ebx,ebx
// cmp esi,ebx
// mov ebp,8000
// mov edx,2
// je ff8_en.525369
// cmp word ptr ds:[esi+21E],dx
// jne ff8_en.525369
// mov al,byte ptr ds:[esi+24F]
// mov cl,byte ptr ds:[esi+24E]
// cmp cl,al
// je ff8_en.525369
// movzx ax,al
// movsx ecx,ax
// lea edi,dword ptr ds:[esi+256]
// xor edx,edx
// push ebx
// push ecx
// mov dl,byte ptr ds:[edi]
// push D
// push edx
// mov dword ptr ss:[esp+34],eax
// call ff8_en.532890
// mov al,byte ptr ss:[esp+34]
// xor ecx,ecx
// mov cl,byte ptr ds:[edi]
// mov byte ptr ds:[esi+24E],al
// mov word ptr ds:[esi+206],bx
// mov word ptr ds:[esi+20A],bx
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov ecx,dword ptr ds:[esi+160]
// and ch,7
// add esp,10
// mov dx,word ptr ds:[eax+C]
// mov dword ptr ds:[esi+160],ecx
// mov word ptr ds:[esi+20C],dx
// mov esi,dword ptr ds:[1D9CF3C]
// mov word ptr ds:[eax+52],bx
// mov edx,2
// or dword ptr ds:[esi+160],ebp
// mov edi,dword ptr ds:[1D9CF40]
// cmp edi,ebx
// je ff8_en.52541C
// cmp word ptr ds:[edi+21E],dx
// jne ff8_en.52541C
// mov al,byte ptr ds:[edi+24F]
// mov cl,byte ptr ds:[edi+24E]
// cmp cl,al
// je ff8_en.52541C
// movzx ax,al
// mov dword ptr ss:[esp+24],eax
// mov esi,edi
// movsx eax,ax
// add edi,256
// xor ecx,ecx
// push ebx
// push eax
// mov cl,byte ptr ds:[edi]
// push D
// push ecx
// call ff8_en.532890
// xor eax,eax
// mov dl,byte ptr ss:[esp+34]
// mov al,byte ptr ds:[edi]
// mov edi,dword ptr ds:[1D9CF40]
// add esp,10
// mov byte ptr ds:[esi+24E],dl
// mov eax,dword ptr ds:[eax*4+1DCB340]
// mov word ptr ds:[esi+206],bx
// mov word ptr ds:[esi+20A],bx
// mov edx,2
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bx
// mov word ptr ds:[esi+20C],cx
// mov ecx,dword ptr ds:[esi+160]
// and ch,7
// mov dword ptr ds:[esi+160],ecx
// mov eax,dword ptr ds:[edi+160]
// mov esi,dword ptr ds:[1D9CF3C]
// or eax,ebp
// mov dword ptr ds:[edi+160],eax
// mov eax,dword ptr ds:[1D9CF44]
// cmp eax,ebx
// je ff8_en.5254D1
// cmp word ptr ds:[eax+21E],dx
// jne ff8_en.5254D1
// mov cl,byte ptr ds:[eax+24F]
// cmp byte ptr ds:[eax+24E],cl
// je ff8_en.5254D1
// movzx cx,cl
// movsx edx,cx
// mov esi,eax
// lea edi,dword ptr ds:[eax+256]
// xor eax,eax
// push ebx
// mov al,byte ptr ds:[edi]
// push edx
// push D
// push eax
// mov dword ptr ss:[esp+34],ecx
// call ff8_en.532890
// mov cl,byte ptr ss:[esp+34]
// xor edx,edx
// mov dl,byte ptr ds:[edi]
// mov byte ptr ds:[esi+24E],cl
// mov edi,dword ptr ds:[1D9CF40]
// add esp,10
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,7
// mov word ptr ds:[esi+206],bx
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],bx
// mov eax,dword ptr ds:[1D9CF44]
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[esi+20A],bx
// mov ecx,dword ptr ds:[eax+160]
// mov esi,dword ptr ds:[1D9CF3C]
// or ecx,ebp
// mov edx,2
// mov dword ptr ds:[eax+160],ecx
// cmp esi,ebx
// je ff8_en.5254DE
// cmp word ptr ds:[esi+21E],dx
// jne ff8_en.5254F8
// cmp edi,ebx
// je ff8_en.5254EB
// cmp word ptr ds:[edi+21E],dx
// jne ff8_en.5254F8
// cmp eax,ebx
// je ff8_en.525505
// cmp word ptr ds:[eax+21E],dx
// je ff8_en.525505
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// add esp,10
// ret 
// cmp esi,ebx
// mov ecx,FFFFFFFE
// je ff8_en.525522
// mov ebp,dword ptr ds:[esi+160]
// and ebp,ecx
// mov dword ptr ds:[esi+160],ebp
// mov byte ptr ds:[esi+23C],bl
// cmp edi,ebx
// je ff8_en.52553A
// mov esi,dword ptr ds:[edi+160]
// and esi,ecx
// mov dword ptr ds:[edi+160],esi
// mov byte ptr ds:[edi+23C],bl
// cmp eax,ebx
// je ff8_en.525552
// mov esi,dword ptr ds:[eax+160]
// and esi,ecx
// mov dword ptr ds:[eax+160],esi
// mov byte ptr ds:[eax+23C],bl
// pop edi
// pop esi
// pop ebp
// mov eax,edx
// pop ebx
// add esp,10
// ret 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push ebp
// mov ebp,dword ptr ss:[esp+10]
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov eax,ebp
// push edi
// sub eax,dword ptr ds:[esi+190]
// cdq 
// and edx,FFF
// add eax,edx
// mov edx,dword ptr ds:[esi+194]
// mov ecx,eax
// mov eax,dword ptr ss:[esp+1C]
// sub eax,edx
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov edx,eax
// sar ecx,C
// imul edx,eax
// mov eax,ecx
// imul eax,ecx
// movsx ecx,word ptr ds:[1CE476A]
// add edx,eax
// cmp edx,3F480
// jl ff8_en.5255DE
// mov eax,ecx
// shl eax,7
// sub eax,ecx
// shl eax,3
// sub eax,ecx
// movzx bx,byte ptr ds:[esi+251]
// lea eax,dword ptr ds:[eax+eax*4]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,3
// sar ecx,9
// mov word ptr ds:[esi+1FE],cx
// jmp ff8_en.525604
// lea eax,dword ptr ds:[ecx+ecx*8]
// shl eax,6
// sub eax,ecx
// movzx bx,byte ptr ds:[esi+250]
// lea eax,dword ptr ds:[eax+eax*2]
// lea eax,dword ptr ds:[ecx+eax*2]
// lea ecx,dword ptr ds:[eax+eax*4]
// shl ecx,2
// sar ecx,9
// mov word ptr ds:[esi+1FE],cx
// movsx edx,bx
// xor edi,edi
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// push edi
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// mov word ptr ds:[esi+21E],di
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// mov ecx,dword ptr ss:[esp+1C]
// mov byte ptr ds:[esi+24E],bl
// mov byte ptr ds:[esi+23C],1
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// mov edx,dword ptr ss:[esp+20]
// and ah,7
// mov dword ptr ds:[esi+160],eax
// or ah,20
// mov word ptr ds:[esi+21A],8
// mov dword ptr ds:[esi+1B4],ebp
// mov dword ptr ds:[esi+1B8],ecx
// mov dword ptr ds:[esi+1BC],edx
// mov dword ptr ds:[esi+160],eax
// pop edi
// pop esi
// pop ebp
// pop ebx
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.525727
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+23C],2
// movsx edx,cl
// mov word ptr ds:[eax+21E],0
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1D8],dx
// movsx edx,cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B4],edx
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1FC],cx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.525721
// mov byte ptr ds:[eax+23C],0
// mov eax,3
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5257E2
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+23C],2
// movsx edx,cl
// mov word ptr ds:[eax+21E],0
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1D8],dx
// movsx edx,cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1BC],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B4],edx
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1FC],cx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.5257DC
// mov byte ptr ds:[eax+23C],0
// mov eax,3
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5258B9
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+23C],2
// movsx edx,cl
// mov word ptr ds:[eax+21E],0
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// push ebx
// mov word ptr ds:[eax+1D8],dx
// push esi
// mov esi,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// xor ebx,ebx
// dec cl
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov bl,byte ptr ds:[edx+esi+C2]
// pop esi
// mov edx,ebx
// pop ebx
// mov ecx,edx
// shl ecx,4
// add ecx,edx
// mov edx,dword ptr ds:[<entity_other>]
// lea ecx,dword ptr ds:[ecx+ecx*8]
// lea ecx,dword ptr ds:[edx+ecx*4]
// mov edx,dword ptr ds:[ecx+190]
// mov dword ptr ds:[eax+1B4],edx
// mov edx,dword ptr ds:[ecx+194]
// mov dword ptr ds:[eax+1B8],edx
// mov edx,dword ptr ds:[ecx+198]
// mov cx,word ptr ds:[ecx+1FA]
// mov dword ptr ds:[eax+1BC],edx
// mov word ptr ds:[eax+1FC],cx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.5258B3
// mov byte ptr ds:[eax+23C],0
// mov eax,3
// ret 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[1CE490E],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.525A0C
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// push edi
// xor edi,edi
// mov byte ptr ds:[esi+23C],3
// mov word ptr ds:[esi+21A],1
// mov word ptr ds:[esi+21E],di
// mov bx,word ptr ds:[esi+edx*4]
// dec al
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+184],al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// mov byte ptr ds:[esi+24E],bl
// mov dl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// add esp,10
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov al,byte ptr ds:[esi+184]
// mov word ptr ds:[esi+20C],cx
// movsx ecx,al
// or dh,20
// pop edi
// mov dword ptr ds:[esi+160],edx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1BC],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// pop ebx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B8],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],al
// mov ax,word ptr ss:[esp+C]
// mov word ptr ds:[esi+1FC],ax
// mov eax,1
// pop esi
// ret 
// mov eax,2
// cmp word ptr ds:[esi+21E],ax
// jne ff8_en.525A05
// mov byte ptr ds:[esi+23C],0
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.525B3A
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// push edi
// xor edi,edi
// mov byte ptr ds:[esi+23C],3
// mov word ptr ds:[esi+21A],di
// mov word ptr ds:[esi+21E],di
// mov bx,word ptr ds:[esi+edx*4]
// dec al
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+184],al
// movsx eax,bx
// push edi
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// mov byte ptr ds:[esi+24E],bl
// mov dl,byte ptr ds:[esi+256]
// mov word ptr ds:[esi+206],di
// mov word ptr ds:[esi+20A],di
// add esp,10
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],di
// mov al,byte ptr ds:[esi+184]
// mov word ptr ds:[esi+20C],cx
// movsx ecx,al
// or dh,20
// pop edi
// mov dword ptr ds:[esi+160],edx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1BC],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// pop ebx
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B8],edx
// movsx ecx,al
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[esi+ecx*4]
// shl edx,C
// dec al
// mov dword ptr ds:[esi+1B4],edx
// mov byte ptr ds:[esi+184],al
// mov ax,word ptr ss:[esp+C]
// mov word ptr ds:[esi+1FC],ax
// mov eax,1
// pop esi
// ret 
// mov eax,2
// cmp word ptr ds:[esi+21E],ax
// jne ff8_en.525B33
// mov byte ptr ds:[esi+23C],0
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.525C7F
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+23C],4
// movsx edx,cl
// mov word ptr ds:[eax+21A],1
// mov word ptr ds:[eax+21E],0
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1BC],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B4],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C4],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C0],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B0],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1AC],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1A8],edx
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1FC],cx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.525C79
// mov byte ptr ds:[eax+23C],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.525DBD
// xor ecx,ecx
// mov byte ptr ds:[eax+23C],4
// mov word ptr ds:[eax+21A],cx
// mov word ptr ds:[eax+21E],cx
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1BC],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B4],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C8],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C4],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1C0],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1B0],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1AC],edx
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// mov edx,dword ptr ds:[eax+edx*4]
// shl edx,C
// dec cl
// mov dword ptr ds:[eax+1A8],edx
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1FC],cx
// mov eax,1
// ret 
// cmp word ptr ds:[eax+21E],2
// jne ff8_en.525DB7
// mov byte ptr ds:[eax+23C],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EC],dx
// mov word ptr ds:[eax+1EE],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E6],dx
// mov word ptr ds:[eax+1E8],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1E0],dx
// mov word ptr ds:[eax+1FC],cx
// xor ecx,ecx
// mov word ptr ds:[eax+1E2],dx
// mov byte ptr ds:[eax+245],cl
// mov word ptr ds:[eax+21E],cx
// mov word ptr ds:[eax+1F4],cx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+245],1
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F2],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F0],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EA],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E4],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EE],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E8],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E2],dx
// mov word ptr ds:[eax+1F4],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+245],2
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F2],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F0],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EA],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E4],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EE],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E8],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E2],dx
// mov word ptr ds:[eax+1F4],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+245],1
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F2],dx
// mov dx,word ptr ds:[eax+1E4]
// mov word ptr ds:[eax+1E2],dx
// mov dx,word ptr ds:[eax+1EA]
// mov word ptr ds:[eax+1E8],dx
// mov dx,word ptr ds:[eax+1F0]
// mov word ptr ds:[eax+1EE],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F0],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EA],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E4],dx
// mov word ptr ds:[eax+1F4],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// mov byte ptr ds:[eax+245],2
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F2],dx
// mov dx,word ptr ds:[eax+1E4]
// mov word ptr ds:[eax+1E2],dx
// mov dx,word ptr ds:[eax+1EA]
// mov word ptr ds:[eax+1E8],dx
// mov dx,word ptr ds:[eax+1F0]
// mov word ptr ds:[eax+1EE],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1F0],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1EA],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1E4],dx
// mov word ptr ds:[eax+1F4],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// cmp byte ptr ds:[ecx+245],3
// sete al
// inc eax
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4904],1
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// mov byte ptr ds:[1CE4904],0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// call <ff8_en.s_GETDRESS>
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov cx,word ptr ds:[1CE4866]
// xor eax,eax
// cmp cx,word ptr ds:[1CE4864]
// sete al
// inc eax
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov word ptr ds:[1CE4866],0
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CE4864],dx
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[1CE4862],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[ecx+240],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// xor edx,edx
// push 0
// push 0
// mov ecx,dword ptr ds:[eax+160]
// mov dl,byte ptr ds:[eax+256]
// and ecx,FFD7FFFF
// push 2E
// or ecx,100000
// push edx
// mov dword ptr ds:[eax+160],ecx
// call ff8_en.532340
// add esp,10
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// xor edx,edx
// push 0
// push 0
// mov ecx,dword ptr ds:[eax+160]
// mov dl,byte ptr ds:[eax+256]
// and ecx,FFE7FFFF
// push 2F
// or ecx,200000
// push edx
// mov dword ptr ds:[eax+160],ecx
// call ff8_en.532340
// add esp,10
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov ecx,dword ptr ds:[eax+160]
// and ecx,FFCFFFFF
// or ecx,80000
// mov dword ptr ds:[eax+160],ecx
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// xor ecx,ecx
// mov byte ptr ds:[eax+263],dl
// mov cl,dl
// xor edx,edx
// mov dl,byte ptr ds:[eax+256]
// push ecx
// push 0
// push 27
// push edx
// call ff8_en.532340
// add esp,10
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// mov bx,word ptr ss:[esp+C]
// push esi
// mov esi,dword ptr ss:[esp+C]
// movsx eax,bx
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov cx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],0
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],cx
// and ah,7
// mov dword ptr ds:[esi+160],eax
// pop esi
// pop ebx
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cx,word ptr ds:[eax+160]
// mov dl,byte ptr ds:[eax+24E]
// mov word ptr ds:[eax+20E],cx
// mov cx,word ptr ds:[eax+206]
// mov byte ptr ds:[eax+24D],dl
// mov dx,word ptr ds:[eax+208]
// mov word ptr ds:[eax+210],cx
// mov cx,word ptr ds:[eax+20A]
// mov word ptr ds:[eax+212],dx
// mov dx,word ptr ds:[eax+20C]
// mov word ptr ds:[eax+214],cx
// mov word ptr ds:[eax+216],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// push 0
// mov al,byte ptr ds:[esi+24D]
// mov cx,word ptr ds:[esi+210]
// mov dx,word ptr ds:[esi+212]
// mov byte ptr ds:[esi+24E],al
// and eax,FF
// mov word ptr ds:[esi+206],cx
// mov cx,word ptr ds:[esi+214]
// push eax
// xor eax,eax
// mov word ptr ds:[esi+208],dx
// mov al,byte ptr ds:[esi+256]
// mov dx,word ptr ds:[esi+216]
// push D
// push eax
// mov word ptr ds:[esi+20A],cx
// mov word ptr ds:[esi+20C],dx
// call ff8_en.532890
// mov ax,word ptr ds:[esi+206]
// xor ecx,ecx
// mov cl,byte ptr ds:[esi+256]
// and word ptr ds:[esi+20E],F800
// add esp,10
// mov edx,dword ptr ds:[ecx*4+1DCB340]
// mov ecx,dword ptr ds:[esi+160]
// and ch,7
// mov word ptr ds:[edx+52],ax
// mov ax,word ptr ds:[esi+20E]
// and eax,FFFF
// or ecx,eax
// mov eax,2
// mov dword ptr ds:[esi+160],ecx
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dx,word ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov word ptr ds:[ecx+208],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov eax,dword ptr ds:[eax+160]
// and eax,800
// neg eax
// sbb eax,eax
// neg eax
// inc eax
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+C]
// xor ecx,ecx
// push 0
// movzx bx,byte ptr ds:[esi+24F]
// mov cl,byte ptr ds:[esi+256]
// movsx eax,bx
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[eax+52],0
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.5265FC
// push ebx
// mov ebx,dword ptr ss:[esp+10]
// movsx edx,bx
// xor eax,eax
// push 0
// mov al,byte ptr ds:[esi+256]
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// pop ebx
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],0
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// and ah,47
// or ah,40
// mov dword ptr ds:[esi+160],eax
// mov eax,1
// pop esi
// ret 
// mov eax,dword ptr ds:[esi+160]
// test ah,8
// mov eax,3
// jne ff8_en.526611
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.5266AC
// push ebx
// mov ebx,dword ptr ss:[esp+10]
// movsx edx,bx
// xor eax,eax
// push 0
// mov al,byte ptr ds:[esi+256]
// push edx
// push D
// push eax
// call ff8_en.532890
// xor ecx,ecx
// add esp,10
// mov cl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[ecx*4+1DCB340]
// pop ebx
// mov dx,word ptr ds:[eax+C]
// mov word ptr ds:[eax+52],0
// mov eax,dword ptr ds:[esi+160]
// mov word ptr ds:[esi+20C],dx
// and ah,87
// or ah,80
// mov dword ptr ds:[esi+160],eax
// mov eax,1
// pop esi
// ret 
// mov eax,dword ptr ds:[esi+160]
// test ah,8
// mov eax,3
// jne ff8_en.5266C1
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.526733
// movsx edx,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+edx*4-4]
// lea eax,dword ptr ds:[esi+edx*4]
// push ecx
// mov dx,word ptr ds:[eax]
// mov eax,dword ptr ss:[esp+10]
// push edx
// push eax
// push esi
// call ff8_en.526750
// mov cl,byte ptr ds:[esi+184]
// mov eax,dword ptr ds:[esi+160]
// add esp,10
// add cl,FE
// or ah,40
// mov byte ptr ds:[esi+184],cl
// mov dword ptr ds:[esi+160],eax
// mov eax,1
// pop esi
// ret 
// mov eax,dword ptr ds:[esi+160]
// test ah,8
// mov eax,3
// jne ff8_en.526748
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov al,byte ptr ds:[<current_entity>]
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov cl,byte ptr ds:[esi+256]
// cmp al,cl
// je ff8_en.526766
// jmp ff8_en.526764
// mov eax,dword ptr ss:[esp+10]
// mov edx,dword ptr ss:[esp+C]
// push edi
// mov edi,dword ptr ss:[esp+18]
// shl edi,4
// sub edi,10
// and ecx,FF
// shl eax,4
// mov word ptr ds:[esi+20C],di
// mov edi,dword ptr ds:[ecx*4+1DCB340]
// push 0
// push edx
// add eax,FFFFFFF0
// push D
// push ecx
// mov byte ptr ds:[esi+24E],dl
// mov word ptr ds:[esi+20A],ax
// mov word ptr ds:[esi+206],ax
// mov word ptr ds:[edi+52],ax
// call ff8_en.532890
// mov ecx,dword ptr ds:[esi+160]
// add esp,10
// and ch,7
// cmp word ptr ds:[esi+20A],0
// mov dword ptr ds:[esi+160],ecx
// pop edi
// jge ff8_en.5267E2
// push 386
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// xor ecx,ecx
// xor eax,eax
// mov cl,byte ptr ds:[esi+256]
// mov edx,dword ptr ds:[ecx*4+1DCB340]
// movsx ecx,word ptr ds:[esi+20C]
// mov ax,word ptr ds:[edx+C]
// cmp ecx,eax
// jle ff8_en.526804
// jmp ff8_en.526802
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.526873
// movsx edx,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+edx*4-4]
// lea eax,dword ptr ds:[esi+edx*4]
// push ecx
// mov dx,word ptr ds:[eax]
// mov eax,dword ptr ss:[esp+10]
// push edx
// push eax
// push esi
// call ff8_en.526750
// mov cl,byte ptr ds:[esi+184]
// mov eax,dword ptr ds:[esi+160]
// add esp,10
// add cl,FE
// or ah,80
// mov byte ptr ds:[esi+184],cl
// mov dword ptr ds:[esi+160],eax
// mov eax,1
// pop esi
// ret 
// mov eax,dword ptr ds:[esi+160]
// test ah,8
// mov eax,3
// jne ff8_en.526888
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// mov ebx,dword ptr ss:[esp+C]
// push esi
// mov esi,dword ptr ss:[esp+C]
// movsx eax,bx
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,47
// mov cx,word ptr ds:[eax+C]
// or dh,40
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[eax+52],0
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// mov ebx,dword ptr ss:[esp+C]
// push esi
// mov esi,dword ptr ss:[esp+C]
// movsx eax,bx
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,87
// mov cx,word ptr ds:[eax+C]
// or dh,80
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[eax+52],0
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// movsx eax,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+eax*4-4]
// mov dx,word ptr ds:[esi+eax*4]
// lea eax,dword ptr ds:[esi+eax*4]
// push ecx
// mov eax,dword ptr ss:[esp+10]
// push edx
// push eax
// push esi
// call ff8_en.526750
// mov cl,byte ptr ds:[esi+184]
// mov eax,dword ptr ds:[esi+160]
// add esp,10
// add cl,FE
// or ah,40
// mov byte ptr ds:[esi+184],cl
// mov dword ptr ds:[esi+160],eax
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// movsx eax,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+eax*4-4]
// mov dx,word ptr ds:[esi+eax*4]
// lea eax,dword ptr ds:[esi+eax*4]
// push ecx
// mov eax,dword ptr ss:[esp+10]
// push edx
// push eax
// push esi
// call ff8_en.526750
// mov cl,byte ptr ds:[esi+184]
// mov eax,dword ptr ds:[esi+160]
// add esp,10
// add cl,FE
// or ah,80
// mov byte ptr ds:[esi+184],cl
// mov dword ptr ds:[esi+160],eax
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// push ebx
// mov ebx,dword ptr ss:[esp+C]
// push esi
// mov esi,dword ptr ss:[esp+C]
// movsx eax,bx
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[esi+256]
// push eax
// push D
// push ecx
// call ff8_en.532890
// xor edx,edx
// add esp,10
// mov dl,byte ptr ds:[esi+256]
// mov byte ptr ds:[esi+24E],bl
// mov word ptr ds:[esi+206],0
// mov word ptr ds:[esi+20A],0
// mov eax,dword ptr ds:[edx*4+1DCB340]
// mov edx,dword ptr ds:[esi+160]
// and dh,27
// mov cx,word ptr ds:[eax+C]
// or dh,20
// mov word ptr ds:[esi+20C],cx
// mov dword ptr ds:[esi+160],edx
// mov word ptr ds:[eax+52],0
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// movsx eax,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+eax*4-4]
// mov dx,word ptr ds:[esi+eax*4]
// lea eax,dword ptr ds:[esi+eax*4]
// push ecx
// mov eax,dword ptr ss:[esp+10]
// push edx
// push eax
// push esi
// call ff8_en.526750
// mov cl,byte ptr ds:[esi+184]
// mov eax,dword ptr ds:[esi+160]
// add esp,10
// add cl,FE
// or ah,20
// mov byte ptr ds:[esi+184],cl
// mov dword ptr ds:[esi+160],eax
// mov eax,3
// pop esi
// ret 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// mov cl,byte ptr ds:[eax+184]
// lea esi,dword ptr ds:[eax+18A]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+18C],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+18B],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,byte ptr ds:[1D9CDDC]
// mov byte ptr ds:[esi],dl
// test cl,2
// jne ff8_en.526B6A
// xor ecx,ecx
// push 0
// mov cl,byte ptr ds:[eax+256]
// push esi
// push 10
// push ecx
// call ff8_en.532340
// add esp,10
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push esi
// xor esi,esi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ss:[esp+A],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ss:[esp+9],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,byte ptr ds:[<entity_count_other>]
// mov eax,dword ptr ds:[<entity_other>]
// test cl,cl
// mov byte ptr ss:[esp+8],dl
// jbe ff8_en.526C23
// push edi
// lea edi,dword ptr ds:[eax+18B]
// test byte ptr ds:[1D9CDDC],2
// jne ff8_en.526BF4
// lea eax,dword ptr ss:[esp+C]
// push 0
// push eax
// push 10
// push esi
// call ff8_en.532340
// add esp,10
// mov cl,byte ptr ss:[esp+C]
// mov byte ptr ds:[edi-1],cl
// mov dl,byte ptr ss:[esp+D]
// mov byte ptr ds:[edi],dl
// mov al,byte ptr ss:[esp+E]
// mov byte ptr ds:[edi+1],al
// xor ecx,ecx
// mov cl,byte ptr ds:[<entity_count_other>]
// add edi,264
// inc esi
// cmp esi,ecx
// jl ff8_en.526BD9
// pop edi
// mov eax,2
// pop esi
// ret 
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[ecx+257],dl
// mov dl,byte ptr ds:[1D9CDDC]
// mov eax,2
// test al,dl
// jne ff8_en.526C75
// mov cl,byte ptr ds:[ecx+257]
// xor edx,edx
// mov dl,byte ptr ds:[<current_entity>]
// mov edx,dword ptr ds:[edx*4+1DCB340]
// mov byte ptr ds:[edx+61],cl
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cl,byte ptr ds:[1D9CDDC]
// mov word ptr ds:[eax+220],dx
// test cl,2
// jne ff8_en.526CC5
// xor ecx,ecx
// mov cl,byte ptr ds:[eax+256]
// mov ax,word ptr ds:[eax+220]
// mov edx,dword ptr ds:[ecx*4+1DCB340]
// mov word ptr ds:[edx+62],ax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push ebx
// mov bl,byte ptr ds:[ecx+184]
// movsx eax,bl
// mov eax,dword ptr ds:[ecx+eax*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25C],al
// mov byte ptr ds:[ecx+184],bl
// mov byte ptr ds:[ecx+25B],al
// mov byte ptr ds:[ecx+25A],al
// mov byte ptr ds:[ecx+259],al
// mov byte ptr ds:[ecx+260],al
// mov byte ptr ds:[ecx+25F],al
// mov byte ptr ds:[ecx+25E],al
// mov byte ptr ds:[ecx+25D],al
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push ebx
// mov bl,byte ptr ds:[ecx+184]
// movsx eax,bl
// mov eax,dword ptr ds:[ecx+eax*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25C],al
// movsx edx,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+edx*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25B],al
// movsx eax,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+eax*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25A],al
// movsx edx,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+edx*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+259],al
// movsx eax,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+eax*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+260],al
// movsx edx,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+edx*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25F],al
// movsx eax,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+eax*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25E],al
// movsx edx,bl
// mov byte ptr ds:[ecx+184],bl
// mov eax,dword ptr ds:[ecx+edx*4]
// cdq 
// and edx,3
// add eax,edx
// sar eax,2
// dec bl
// mov byte ptr ds:[ecx+25D],al
// mov byte ptr ds:[ecx+184],bl
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[ecx+261],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov dl,byte ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov byte ptr ds:[ecx+241],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.526EFC
// xor ecx,ecx
// mov byte ptr ds:[eax+23C],1
// mov word ptr ds:[eax+21E],cx
// mov word ptr ds:[eax+21A],cx
// mov word ptr ds:[eax+1FE],cx
// movsx ecx,byte ptr ds:[eax+184]
// mov edx,dword ptr ds:[eax+ecx*4-8]
// shl edx,C
// mov dword ptr ds:[eax+1B4],edx
// mov edx,dword ptr ds:[eax+ecx*4-4]
// shl edx,C
// mov dword ptr ds:[eax+1B8],edx
// mov ecx,dword ptr ds:[eax+ecx*4]
// shl ecx,C
// mov dword ptr ds:[eax+1BC],ecx
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+184]
// mov dx,word ptr ds:[eax+200]
// add cl,FD
// mov byte ptr ds:[eax+23C],0
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1FE],dx
// mov word ptr ds:[eax+21E],2
// mov eax,2
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// mov edx,dword ptr ds:[ecx*4+1D9D020]
// push edx
// push esi
// call ff8_en.47A880
// add esp,8
// mov byte ptr ds:[esi+241],al
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// xor edx,edx
// mov al,byte ptr ds:[esi+184]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov byte ptr ds:[esi+184],al
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,byte ptr ds:[eax+ecx+C2]
// mov ecx,edx
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,ecx
// shl eax,4
// add eax,ecx
// lea ecx,dword ptr ds:[eax+eax*8]
// lea eax,dword ptr ds:[edx+ecx*4]
// push eax
// push esi
// call ff8_en.47A880
// add esp,8
// mov byte ptr ds:[esi+241],al
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527055
// mov cl,byte ptr ds:[eax+184]
// push esi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],1
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov cx,si
// mov word ptr ds:[eax+1DE],si
// cmp dx,cx
// pop esi
// jge ff8_en.527065
// add ecx,FFFFFF00
// mov word ptr ds:[eax+1DE],cx
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.52706A
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5270F5
// mov cl,byte ptr ds:[eax+184]
// push esi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],1
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov cx,si
// mov word ptr ds:[eax+1DE],si
// cmp dx,cx
// pop esi
// jle ff8_en.527105
// add ecx,100
// mov word ptr ds:[eax+1DE],cx
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.52710A
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527195
// mov cl,byte ptr ds:[eax+184]
// push esi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],2
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov cx,si
// mov word ptr ds:[eax+1DE],si
// cmp dx,cx
// pop esi
// jge ff8_en.5271A5
// add ecx,FFFFFF00
// mov word ptr ds:[eax+1DE],cx
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.5271AA
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527235
// mov cl,byte ptr ds:[eax+184]
// push esi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],2
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov cx,si
// mov word ptr ds:[eax+1DE],si
// cmp dx,cx
// pop esi
// jle ff8_en.527245
// add ecx,100
// mov word ptr ds:[eax+1DE],cx
// mov eax,1
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.52724A
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// push esi
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527307
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],1
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1DE],si
// movsx ecx,si
// movsx edi,dx
// sub ecx,edi
// mov byte ptr ds:[eax+243],0
// pop edi
// jns ff8_en.5272D2
// neg ecx
// cmp ecx,80
// jle ff8_en.527317
// cmp dx,si
// jge ff8_en.5272F3
// add esi,FFFFFF00
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// add esi,100
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.52731C
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// push esi
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5273D7
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],1
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1DE],si
// movsx ecx,si
// movsx edi,dx
// sub ecx,edi
// mov byte ptr ds:[eax+243],0
// pop edi
// jns ff8_en.5273A2
// neg ecx
// cmp ecx,80
// jle ff8_en.5273E7
// cmp dx,si
// jge ff8_en.5273C3
// add esi,FFFFFF00
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// add esi,100
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.5273EC
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// push esi
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.5274A7
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],2
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1DE],si
// movsx ecx,si
// movsx edi,dx
// sub ecx,edi
// mov byte ptr ds:[eax+243],0
// pop edi
// jns ff8_en.527472
// neg ecx
// cmp ecx,80
// jle ff8_en.5274B7
// cmp dx,si
// jge ff8_en.527493
// add esi,FFFFFF00
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// add esi,100
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.5274BC
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// push esi
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527577
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+242],dl
// mov byte ptr ds:[eax+243],0
// movzx dx,byte ptr ds:[eax+241]
// movsx esi,cl
// mov byte ptr ds:[eax+244],2
// mov word ptr ds:[eax+1DC],dx
// mov si,word ptr ds:[eax+esi*4]
// dec cl
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+1DE],si
// movsx ecx,si
// movsx edi,dx
// sub ecx,edi
// mov byte ptr ds:[eax+243],0
// pop edi
// jns ff8_en.527542
// neg ecx
// cmp ecx,80
// jle ff8_en.527587
// cmp dx,si
// jge ff8_en.527563
// add esi,FFFFFF00
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// add esi,100
// mov word ptr ds:[eax+1DE],si
// mov eax,1
// pop esi
// ret 
// mov cl,byte ptr ds:[eax+244]
// mov eax,2
// cmp cl,3
// je ff8_en.52758C
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.52766E
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx ecx,al
// movzx dx,byte ptr ds:[esi+241]
// mov ecx,dword ptr ds:[esi+ecx*4]
// dec al
// mov byte ptr ds:[esi+184],al
// mov byte ptr ds:[esi+243],0
// mov eax,dword ptr ds:[ecx*4+1D9D020]
// mov word ptr ds:[esi+1DC],dx
// push eax
// push esi
// call ff8_en.47A880
// mov dx,word ptr ds:[esi+1DC]
// add esp,8
// movzx ax,al
// mov byte ptr ds:[esi+242],bl
// cmp dx,ax
// mov word ptr ds:[esi+1DE],ax
// pop ebx
// jne ff8_en.52761F
// mov eax,2
// pop esi
// ret 
// push edi
// mov byte ptr ds:[esi+244],1
// movsx edi,dx
// movsx ecx,ax
// sub ecx,edi
// mov byte ptr ds:[esi+243],0
// pop edi
// jns ff8_en.52763B
// neg ecx
// cmp ecx,80
// jle ff8_en.52767D
// cmp dx,ax
// jge ff8_en.52765B
// add eax,FFFFFF00
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// add eax,100
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// mov al,byte ptr ds:[esi+244]
// cmp al,3
// mov eax,2
// je ff8_en.527682
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.52776E
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx ecx,al
// movzx dx,byte ptr ds:[esi+241]
// mov ecx,dword ptr ds:[esi+ecx*4]
// dec al
// mov byte ptr ds:[esi+184],al
// mov byte ptr ds:[esi+243],0
// mov eax,dword ptr ds:[ecx*4+1D9D020]
// mov word ptr ds:[esi+1DC],dx
// push eax
// push esi
// call ff8_en.47A880
// mov dx,word ptr ds:[esi+1DC]
// add esp,8
// movzx ax,al
// mov byte ptr ds:[esi+242],bl
// cmp dx,ax
// mov word ptr ds:[esi+1DE],ax
// pop ebx
// jne ff8_en.52771F
// mov eax,2
// pop esi
// ret 
// push edi
// mov byte ptr ds:[esi+244],2
// movsx edi,dx
// movsx ecx,ax
// sub ecx,edi
// mov byte ptr ds:[esi+243],0
// pop edi
// jns ff8_en.52773B
// neg ecx
// cmp ecx,80
// jle ff8_en.52777D
// cmp dx,ax
// jge ff8_en.52775B
// add eax,FFFFFF00
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// add eax,100
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// mov al,byte ptr ds:[esi+244]
// cmp al,3
// mov eax,2
// je ff8_en.527782
// mov eax,1
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527889
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movzx dx,byte ptr ds:[esi+241]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov word ptr ds:[esi+1DC],dx
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[esi+184],al
// xor eax,eax
// mov byte ptr ds:[esi+243],0
// mov al,byte ptr ds:[edx+ecx+C2]
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// push esi
// call ff8_en.47A880
// mov cx,word ptr ds:[esi+1DC]
// add esp,8
// movzx ax,al
// mov byte ptr ds:[esi+242],bl
// cmp cx,ax
// mov word ptr ds:[esi+1DE],ax
// pop ebx
// jne ff8_en.52783A
// mov eax,2
// pop esi
// ret 
// push edi
// mov byte ptr ds:[esi+244],1
// movsx edi,cx
// movsx edx,ax
// sub edx,edi
// mov byte ptr ds:[esi+243],0
// pop edi
// jns ff8_en.527856
// neg edx
// cmp edx,80
// jle ff8_en.527898
// cmp cx,ax
// jge ff8_en.527876
// add eax,FFFFFF00
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// add eax,100
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// mov al,byte ptr ds:[esi+244]
// cmp al,3
// mov eax,2
// je ff8_en.52789D
// mov eax,1
// pop esi
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527999
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movzx dx,byte ptr ds:[esi+241]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov word ptr ds:[esi+1DC],dx
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[esi+184],al
// xor eax,eax
// mov byte ptr ds:[esi+243],0
// mov al,byte ptr ds:[edx+ecx+C2]
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// push esi
// call ff8_en.47A880
// mov cx,word ptr ds:[esi+1DC]
// add esp,8
// movzx ax,al
// mov byte ptr ds:[esi+242],bl
// cmp cx,ax
// mov word ptr ds:[esi+1DE],ax
// pop ebx
// jne ff8_en.52794A
// mov eax,2
// pop esi
// ret 
// push edi
// mov byte ptr ds:[esi+244],2
// movsx edi,cx
// movsx edx,ax
// sub edx,edi
// mov byte ptr ds:[esi+243],0
// pop edi
// jns ff8_en.527966
// neg edx
// cmp edx,80
// jle ff8_en.5279A8
// cmp cx,ax
// jge ff8_en.527986
// add eax,FFFFFF00
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// add eax,100
// mov word ptr ds:[esi+1DE],ax
// mov eax,1
// pop esi
// ret 
// mov al,byte ptr ds:[esi+244]
// cmp al,3
// mov eax,2
// je ff8_en.5279AD
// mov eax,1
// pop esi
// ret 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// mov eax,1
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527AA9
// mov al,byte ptr ds:[esi+184]
// push ebx
// movsx edx,al
// dec al
// mov ebx,dword ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movzx dx,byte ptr ds:[esi+241]
// movsx ecx,al
// dec al
// mov ecx,dword ptr ds:[esi+ecx*4]
// mov word ptr ds:[esi+1DC],dx
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[esi+184],al
// xor eax,eax
// mov byte ptr ds:[esi+243],0
// mov al,byte ptr ds:[edx+ecx+C2]
// mov ecx,eax
// shl eax,4
// add eax,ecx
// mov ecx,dword ptr ds:[<entity_other>]
// lea eax,dword ptr ds:[eax+eax*8]
// lea edx,dword ptr ds:[ecx+eax*4]
// push edx
// push esi
// call ff8_en.47A880
// mov cx,word ptr ds:[esi+1DC]
// add esp,8
// movzx ax,al
// mov byte ptr ds:[esi+242],bl
// cmp cx,ax
// mov word ptr ds:[esi+1DE],ax
// pop ebx
// jne ff8_en.527A61
// mov byte ptr ds:[esi+244],3
// mov eax,2
// pop esi
// ret 
// push edi
// mov byte ptr ds:[esi+244],2
// movsx edi,cx
// movsx edx,ax
// sub edx,edi
// mov byte ptr ds:[esi+243],0
// pop edi
// jns ff8_en.527A7D
// neg edx
// cmp edx,80
// jle ff8_en.527AA9
// cmp cx,ax
// jge ff8_en.527A9D
// add eax,FFFFFF00
// mov word ptr ds:[esi+1DE],ax
// mov eax,2
// pop esi
// ret 
// add eax,100
// mov word ptr ds:[esi+1DE],ax
// mov eax,2
// pop esi
// ret 
// mov ecx,dword ptr ss:[esp+4]
// xor eax,eax
// cmp byte ptr ds:[ecx+244],3
// sete al
// inc eax
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cx,word ptr ds:[eax+234]
// sub cx,word ptr ds:[eax+236]
// neg cx
// sbb ecx,ecx
// add ecx,2
// mov eax,ecx
// ret 
// nop 
// nop 
// nop 
// mov edx,dword ptr ss:[esp+4]
// mov eax,1
// mov cl,byte ptr ds:[edx+174]
// shl eax,cl
// mov cl,byte ptr ds:[edx+175]
// test cl,al
// je ff8_en.527B78
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+234],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+232],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+22E],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// xor eax,eax
// mov word ptr ds:[edx+22A],cx
// mov word ptr ds:[edx+236],ax
// mov byte ptr ds:[edx+23B],al
// mov ax,word ptr ds:[edx+234]
// sub ax,word ptr ds:[edx+236]
// neg ax
// sbb eax,eax
// add eax,2
// ret 
// nop 
// mov edx,dword ptr ss:[esp+4]
// mov eax,1
// mov cl,byte ptr ds:[edx+174]
// shl eax,cl
// mov cl,byte ptr ds:[edx+175]
// test cl,al
// je ff8_en.527C19
// mov al,byte ptr ds:[edx+184]
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+234],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+226],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+224],cx
// movsx ecx,al
// dec al
// mov cx,word ptr ds:[edx+ecx*4]
// mov byte ptr ds:[edx+184],al
// mov word ptr ds:[edx+222],cx
// mov word ptr ds:[edx+236],0
// mov byte ptr ds:[edx+23B],1
// mov ax,word ptr ds:[edx+234]
// sub ax,word ptr ds:[edx+236]
// neg ax
// sbb eax,eax
// add eax,2
// ret 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527D0D
// mov al,byte ptr ds:[esi+184]
// push edi
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov word ptr ds:[esi+234],cx
// mov ecx,dword ptr ds:[1CE4C80]
// mov edi,dword ptr ds:[esi+edx*4]
// dec al
// mov byte ptr ds:[esi+184],al
// lea eax,dword ptr ss:[esp+8]
// mov edx,dword ptr ds:[edi*4+1D9D020]
// push eax
// xor eax,eax
// push ecx
// mov al,byte ptr ds:[edx+256]
// push 1E
// push eax
// call ff8_en.531DA0
// mov ecx,dword ptr ds:[edi*4+1D9D020]
// add esp,10
// mov word ptr ds:[esi+236],0
// mov byte ptr ds:[esi+23B],1
// mov eax,dword ptr ds:[ecx+190]
// pop edi
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+222],ax
// mov eax,dword ptr ds:[ecx+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+224],ax
// mov eax,dword ptr ds:[ecx+198]
// mov ecx,dword ptr ss:[esp+8]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// add eax,ecx
// mov word ptr ds:[esi+226],ax
// mov ax,word ptr ds:[esi+234]
// sub ax,word ptr ds:[esi+236]
// pop esi
// neg ax
// sbb eax,eax
// add eax,2
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527E25
// mov al,byte ptr ds:[esi+184]
// push edi
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov word ptr ds:[esi+234],cx
// dec al
// mov ecx,dword ptr ds:[esi+edx*4]
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[esi+184],al
// mov eax,dword ptr ds:[1CE4C80]
// mov cl,byte ptr ds:[ecx+edx+C2]
// lea edx,dword ptr ss:[esp+8]
// mov byte ptr ss:[esp+14],cl
// push edx
// mov edi,dword ptr ss:[esp+18]
// push eax
// and edi,FF
// push 1E
// push edi
// call ff8_en.531DA0
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// add esp,10
// mov word ptr ds:[esi+236],0
// mov byte ptr ds:[esi+23B],1
// lea ecx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[edx+ecx*4+190]
// pop edi
// lea ecx,dword ptr ds:[edx+ecx*4]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+222],ax
// mov eax,dword ptr ds:[ecx+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+224],ax
// mov eax,dword ptr ds:[ecx+198]
// mov ecx,dword ptr ss:[esp+8]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// add eax,ecx
// mov word ptr ds:[esi+226],ax
// mov ax,word ptr ds:[esi+234]
// sub ax,word ptr ds:[esi+236]
// pop esi
// neg ax
// sbb eax,eax
// add eax,2
// add esp,8
// ret 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.527EE8
// mov al,byte ptr ds:[esi+184]
// push 0
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// lea edx,dword ptr ss:[esp+8]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// push edx
// push 20
// push eax
// mov word ptr ds:[esi+234],cx
// call ff8_en.531DA0
// movsx eax,word ptr ss:[esp+14]
// cdq 
// and edx,F
// add esp,10
// add eax,edx
// mov word ptr ds:[esi+236],0
// sar eax,4
// mov word ptr ds:[esi+22A],ax
// mov byte ptr ds:[esi+23B],0
// movsx eax,word ptr ss:[esp+6]
// cdq 
// and edx,F
// add eax,edx
// sar eax,4
// mov word ptr ds:[esi+22E],ax
// movsx eax,word ptr ss:[esp+8]
// cdq 
// and edx,F
// add eax,edx
// sar eax,4
// mov word ptr ds:[esi+232],ax
// mov ax,word ptr ds:[esi+234]
// sub ax,word ptr ds:[esi+236]
// pop esi
// neg ax
// sbb eax,eax
// add eax,2
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.527F98
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+234],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+232],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+22E],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// xor ecx,ecx
// mov word ptr ds:[eax+22A],dx
// mov word ptr ds:[eax+236],cx
// mov byte ptr ds:[eax+23B],cl
// mov eax,2
// ret 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov edx,1
// mov cl,byte ptr ds:[eax+174]
// shl edx,cl
// mov cl,byte ptr ds:[eax+175]
// test cl,dl
// je ff8_en.528029
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+234],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+226],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+224],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[eax+222],dx
// mov word ptr ds:[eax+236],0
// mov byte ptr ds:[eax+23B],1
// mov eax,2
// ret 
// nop 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.528117
// mov al,byte ptr ds:[esi+184]
// push edi
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov word ptr ds:[esi+234],cx
// mov ecx,dword ptr ds:[1CE4C80]
// mov edi,dword ptr ds:[esi+edx*4]
// dec al
// mov byte ptr ds:[esi+184],al
// lea eax,dword ptr ss:[esp+8]
// mov edx,dword ptr ds:[edi*4+1D9D020]
// push eax
// xor eax,eax
// push ecx
// mov al,byte ptr ds:[edx+256]
// push 1E
// push eax
// call ff8_en.531DA0
// mov ecx,dword ptr ds:[edi*4+1D9D020]
// add esp,10
// mov word ptr ds:[esi+236],0
// mov byte ptr ds:[esi+23B],1
// mov eax,dword ptr ds:[ecx+190]
// pop edi
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+222],ax
// mov eax,dword ptr ds:[ecx+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+224],ax
// mov eax,dword ptr ds:[ecx+198]
// mov ecx,dword ptr ss:[esp+8]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// add eax,ecx
// mov word ptr ds:[esi+226],ax
// mov eax,2
// pop esi
// add esp,8
// ret 
// mov eax,2
// pop esi
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.52822F
// mov al,byte ptr ds:[esi+184]
// push edi
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// movsx edx,al
// mov word ptr ds:[esi+234],cx
// dec al
// mov ecx,dword ptr ds:[esi+edx*4]
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov byte ptr ds:[esi+184],al
// mov eax,dword ptr ds:[1CE4C80]
// mov cl,byte ptr ds:[ecx+edx+C2]
// lea edx,dword ptr ss:[esp+8]
// mov byte ptr ss:[esp+14],cl
// push edx
// mov edi,dword ptr ss:[esp+18]
// push eax
// and edi,FF
// push 1E
// push edi
// call ff8_en.531DA0
// mov edx,dword ptr ds:[<entity_other>]
// mov eax,edi
// shl eax,4
// add eax,edi
// add esp,10
// mov word ptr ds:[esi+236],0
// mov byte ptr ds:[esi+23B],1
// lea ecx,dword ptr ds:[eax+eax*8]
// mov eax,dword ptr ds:[edx+ecx*4+190]
// pop edi
// lea ecx,dword ptr ds:[edx+ecx*4]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+222],ax
// mov eax,dword ptr ds:[ecx+194]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// mov word ptr ds:[esi+224],ax
// mov eax,dword ptr ds:[ecx+198]
// mov ecx,dword ptr ss:[esp+8]
// cdq 
// and edx,FFF
// add eax,edx
// sar eax,C
// add eax,ecx
// mov word ptr ds:[esi+226],ax
// mov eax,2
// pop esi
// add esp,8
// ret 
// mov eax,2
// pop esi
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// mov eax,1
// push esi
// mov esi,dword ptr ss:[esp+10]
// mov cl,byte ptr ds:[esi+174]
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.5282E8
// mov al,byte ptr ds:[esi+184]
// push 0
// movsx edx,al
// dec al
// mov cx,word ptr ds:[esi+edx*4]
// mov byte ptr ds:[esi+184],al
// lea edx,dword ptr ss:[esp+8]
// xor eax,eax
// mov al,byte ptr ds:[esi+256]
// push edx
// push 20
// push eax
// mov word ptr ds:[esi+234],cx
// call ff8_en.531DA0
// movsx eax,word ptr ss:[esp+14]
// cdq 
// and edx,F
// add esp,10
// add eax,edx
// mov word ptr ds:[esi+236],0
// sar eax,4
// mov word ptr ds:[esi+22A],ax
// mov byte ptr ds:[esi+23B],0
// movsx eax,word ptr ss:[esp+6]
// cdq 
// and edx,F
// add eax,edx
// sar eax,4
// mov word ptr ds:[esi+22E],ax
// movsx eax,word ptr ss:[esp+8]
// cdq 
// and edx,F
// add eax,edx
// sar eax,4
// mov word ptr ds:[esi+232],ax
// mov eax,2
// pop esi
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+23A],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+239],dl
// movsx edx,cl
// dec cl
// mov dl,byte ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov byte ptr ds:[eax+238],dl
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// lea eax,dword ptr ss:[esp]
// xor ecx,ecx
// push esi
// mov esi,dword ptr ss:[esp+10]
// push 0
// push eax
// mov cl,byte ptr ds:[esi+256]
// push 20
// push ecx
// call ff8_en.531DA0
// movsx eax,word ptr ss:[esp+16]
// cdq 
// and edx,F
// add esp,10
// add eax,edx
// mov word ptr ds:[esi+228],0
// sar eax,4
// mov word ptr ds:[esi+22C],ax
// movsx eax,word ptr ss:[esp+8]
// cdq 
// and edx,F
// add eax,edx
// sar eax,4
// mov word ptr ds:[esi+230],ax
// mov eax,2
// pop esi
// add esp,8
// ret 
// nop 
// mov eax,2
// push esi
// mov byte ptr ds:[1D9CDE2],al
// mov word ptr ds:[1CE4868],ax
// mov edx,FF
// mov word ptr ds:[1CE486A],dx
// mov word ptr ds:[1CE486C],10
// mov word ptr ds:[1CE486E],dx
// mov word ptr ds:[1CE4870],dx
// mov word ptr ds:[1CE4872],dx
// mov si,word ptr ds:[1CE4868]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[ecx+D8],si
// mov si,word ptr ds:[1CE486C]
// mov word ptr ds:[ecx+DC],si
// mov si,word ptr ds:[1CE486A]
// mov word ptr ds:[ecx+DA],si
// mov word ptr ds:[ecx+DE],dx
// mov word ptr ds:[ecx+E0],dx
// mov word ptr ds:[ecx+E2],dx
// mov dx,word ptr ds:[1CE4874]
// pop esi
// mov word ptr ds:[ecx+E4],dx
// mov dx,word ptr ds:[1CE4876]
// mov word ptr ds:[ecx+E6],dx
// mov dx,word ptr ds:[1CE4878]
// mov word ptr ds:[ecx+E8],dx
// mov dx,word ptr ds:[1CE487A]
// mov word ptr ds:[ecx+EA],dx
// mov dx,word ptr ds:[1CE487C]
// mov word ptr ds:[ecx+EC],dx
// mov dx,word ptr ds:[1CE487E]
// mov word ptr ds:[ecx+EE],dx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,3
// mov byte ptr ds:[1D9CDE2],al
// mov word ptr ds:[1CE4868],ax
// mov word ptr ds:[1CE486A],0
// mov word ptr ds:[1CE486C],8
// mov ecx,FF
// mov word ptr ds:[1CE486E],cx
// mov word ptr ds:[1CE4870],cx
// mov word ptr ds:[1CE4872],cx
// mov dx,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],dx
// mov dx,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],dx
// mov dx,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],dx
// mov dx,word ptr ds:[1CE4876]
// mov word ptr ds:[eax+DE],cx
// mov word ptr ds:[eax+E0],cx
// mov word ptr ds:[eax+E2],cx
// mov cx,word ptr ds:[1CE4874]
// mov word ptr ds:[eax+E4],cx
// mov cx,word ptr ds:[1CE4878]
// mov word ptr ds:[eax+E6],dx
// mov dx,word ptr ds:[1CE487A]
// mov word ptr ds:[eax+E8],cx
// mov cx,word ptr ds:[1CE487C]
// mov word ptr ds:[eax+EA],dx
// mov dx,word ptr ds:[1CE487E]
// mov word ptr ds:[eax+EC],cx
// mov word ptr ds:[eax+EE],dx
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push esi
// push edi
// mov word ptr ds:[1CE4868],7
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+C]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov word ptr ds:[1CE4872],dx
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov word ptr ds:[1CE4870],si
// mov di,word ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE486E],di
// mov cx,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],cx
// mov cx,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],cx
// mov cx,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],cx
// mov cx,word ptr ds:[1CE4876]
// mov word ptr ds:[eax+DE],di
// mov word ptr ds:[eax+E0],si
// mov word ptr ds:[eax+E2],dx
// mov dx,word ptr ds:[1CE4874]
// mov word ptr ds:[eax+E4],dx
// mov dx,word ptr ds:[1CE4878]
// mov word ptr ds:[eax+E6],cx
// mov cx,word ptr ds:[1CE487A]
// mov word ptr ds:[eax+E8],dx
// mov dx,word ptr ds:[1CE487C]
// mov word ptr ds:[eax+EA],cx
// mov cx,word ptr ds:[1CE487E]
// mov word ptr ds:[eax+EC],dx
// mov word ptr ds:[eax+EE],cx
// pop edi
// mov eax,2
// pop esi
// ret 
// push esi
// push edi
// mov word ptr ds:[1CE4868],8
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+C]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov word ptr ds:[1CE4872],dx
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov word ptr ds:[1CE4870],si
// mov di,word ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE486E],di
// mov cx,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],cx
// mov cx,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],cx
// mov cx,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],cx
// mov cx,word ptr ds:[1CE4876]
// mov word ptr ds:[eax+DE],di
// mov word ptr ds:[eax+E0],si
// mov word ptr ds:[eax+E2],dx
// mov dx,word ptr ds:[1CE4874]
// mov word ptr ds:[eax+E4],dx
// mov dx,word ptr ds:[1CE4878]
// mov word ptr ds:[eax+E6],cx
// mov cx,word ptr ds:[1CE487A]
// mov word ptr ds:[eax+E8],dx
// mov dx,word ptr ds:[1CE487C]
// mov word ptr ds:[eax+EA],cx
// mov cx,word ptr ds:[1CE487E]
// mov word ptr ds:[eax+EC],dx
// mov word ptr ds:[eax+EE],cx
// pop edi
// mov eax,2
// pop esi
// ret 
// push ebx
// push ebp
// push esi
// push edi
// mov word ptr ds:[1CE4868],5
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+14]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov dx,word ptr ds:[eax+edx*4]
// mov word ptr ds:[1CE486C],dx
// dec cl
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[1CE486E]
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov word ptr ds:[1CE487E],di
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ds:[1CE4872]
// mov word ptr ds:[1CE487A],dx
// mov dx,word ptr ds:[1CE4870]
// mov word ptr ds:[1CE487C],bx
// mov word ptr ds:[1CE4878],cx
// mov word ptr ds:[1CE4876],dx
// mov word ptr ds:[1CE4874],si
// mov bp,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],bp
// mov bp,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],bp
// mov bp,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],bp
// mov word ptr ds:[eax+DE],si
// mov word ptr ds:[eax+E0],dx
// mov word ptr ds:[eax+E2],cx
// mov word ptr ds:[eax+E4],si
// mov word ptr ds:[eax+E6],dx
// mov word ptr ds:[eax+E8],cx
// mov cx,word ptr ds:[1CE487A]
// mov word ptr ds:[eax+EA],cx
// mov word ptr ds:[eax+EC],bx
// mov word ptr ds:[eax+EE],di
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push ebp
// push esi
// push edi
// mov word ptr ds:[1CE4868],6
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+14]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov dx,word ptr ds:[eax+edx*4]
// mov word ptr ds:[1CE486C],dx
// dec cl
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// dec cl
// mov di,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov si,word ptr ds:[1CE486E]
// mov bx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov word ptr ds:[1CE487E],di
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ds:[1CE4872]
// mov word ptr ds:[1CE487A],dx
// mov dx,word ptr ds:[1CE4870]
// mov word ptr ds:[1CE487C],bx
// mov word ptr ds:[1CE4878],cx
// mov word ptr ds:[1CE4876],dx
// mov word ptr ds:[1CE4874],si
// mov bp,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],bp
// mov bp,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],bp
// mov bp,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],bp
// mov word ptr ds:[eax+DE],si
// mov word ptr ds:[eax+E0],dx
// mov word ptr ds:[eax+E2],cx
// mov word ptr ds:[eax+E4],si
// mov word ptr ds:[eax+E6],dx
// mov word ptr ds:[eax+E8],cx
// mov cx,word ptr ds:[1CE487A]
// mov word ptr ds:[eax+EA],cx
// mov word ptr ds:[eax+EC],bx
// mov word ptr ds:[eax+EE],di
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push ebp
// push esi
// push edi
// mov word ptr ds:[1CE4868],5
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+14]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov dx,word ptr ds:[eax+edx*4]
// mov word ptr ds:[1CE486C],dx
// dec cl
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov word ptr ds:[1CE487E],dx
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov word ptr ds:[1CE487C],si
// mov di,word ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// movsx ebx,cl
// dec cl
// mov word ptr ds:[1CE487A],di
// mov bx,word ptr ds:[eax+ebx*4]
// mov byte ptr ds:[eax+184],cl
// movsx ebp,cl
// dec cl
// mov word ptr ds:[1CE4878],bx
// mov bp,word ptr ds:[eax+ebp*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4876],bp
// movsx ebp,cl
// dec cl
// mov bp,word ptr ds:[eax+ebp*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4874],bp
// mov cx,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],cx
// mov cx,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],cx
// mov cx,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],cx
// mov cx,word ptr ds:[1CE486E]
// mov word ptr ds:[eax+DE],cx
// mov cx,word ptr ds:[1CE4870]
// mov word ptr ds:[eax+E0],cx
// mov cx,word ptr ds:[1CE4872]
// mov word ptr ds:[eax+E2],cx
// mov cx,word ptr ds:[1CE4876]
// mov word ptr ds:[eax+E4],bp
// mov word ptr ds:[eax+E6],cx
// mov word ptr ds:[eax+E8],bx
// mov word ptr ds:[eax+EA],di
// mov word ptr ds:[eax+EC],si
// pop edi
// pop esi
// mov word ptr ds:[eax+EE],dx
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// push ebx
// push ebp
// push esi
// push edi
// mov word ptr ds:[1CE4868],6
// mov word ptr ds:[1CE486A],0
// mov eax,dword ptr ss:[esp+14]
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// mov dx,word ptr ds:[eax+edx*4]
// mov word ptr ds:[1CE486C],dx
// dec cl
// movsx edx,cl
// mov byte ptr ds:[eax+184],cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov word ptr ds:[1CE487E],dx
// mov si,word ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// movsx edi,cl
// dec cl
// mov word ptr ds:[1CE487C],si
// mov di,word ptr ds:[eax+edi*4]
// mov byte ptr ds:[eax+184],cl
// movsx ebx,cl
// dec cl
// mov word ptr ds:[1CE487A],di
// mov bx,word ptr ds:[eax+ebx*4]
// mov byte ptr ds:[eax+184],cl
// movsx ebp,cl
// dec cl
// mov word ptr ds:[1CE4878],bx
// mov bp,word ptr ds:[eax+ebp*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4876],bp
// movsx ebp,cl
// dec cl
// mov bp,word ptr ds:[eax+ebp*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ds:[1CE4874],bp
// mov cx,word ptr ds:[1CE4868]
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[eax+D8],cx
// mov cx,word ptr ds:[1CE486C]
// mov word ptr ds:[eax+DC],cx
// mov cx,word ptr ds:[1CE486A]
// mov word ptr ds:[eax+DA],cx
// mov cx,word ptr ds:[1CE486E]
// mov word ptr ds:[eax+DE],cx
// mov cx,word ptr ds:[1CE4870]
// mov word ptr ds:[eax+E0],cx
// mov cx,word ptr ds:[1CE4872]
// mov word ptr ds:[eax+E2],cx
// mov cx,word ptr ds:[1CE4876]
// mov word ptr ds:[eax+E4],bp
// mov word ptr ds:[eax+E6],cx
// mov word ptr ds:[eax+E8],bx
// mov word ptr ds:[eax+EA],di
// mov word ptr ds:[eax+EC],si
// pop edi
// pop esi
// mov word ptr ds:[eax+EE],dx
// pop ebp
// mov eax,2
// pop ebx
// ret 
// nop 
// nop 
// mov ax,word ptr ds:[1CE486A]
// cmp word ptr ds:[1CE486C],ax
// jne ff8_en.528C99
// mov cx,word ptr ds:[1CE4868]
// mov edx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov eax,2
// mov word ptr ds:[edx+D8],cx
// ret 
// mov eax,1
// ret 
// nop 
// mov cl,byte ptr ds:[1D9CDE2]
// mov eax,2
// cmp cl,al
// jne ff8_en.528CBA
// cmp word ptr ds:[1CE4868],0
// jne ff8_en.528CCF
// ret 
// cmp word ptr ds:[1CE4868],3
// jne ff8_en.528CCF
// cmp word ptr ds:[1CE486A],FF
// je ff8_en.528CD4
// mov eax,1
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov word ptr ds:[1CE4868],0
// mov ax,word ptr ds:[1CE4868]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[ecx+D8],ax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov word ptr ds:[1CE4868],4
// mov ax,word ptr ds:[1CE4868]
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov word ptr ds:[ecx+D8],ax
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// push esi
// mov edx,dword ptr ds:[ecx+edx*4]
// and edx,7
// dec al
// push edx
// mov byte ptr ds:[ecx+184],al
// call ff8_en.4A0850
// add esp,8
// mov eax,2
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// push ebx
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebx
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov esi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// push esi
// call <ff8_en.sub_49FA40>
// mov eax,edi
// add esp,8
// sub eax,0
// je ff8_en.528DD9
// dec eax
// je ff8_en.528DD2
// dec eax
// jne ff8_en.528DDE
// xor edi,edi
// jmp ff8_en.528DDE
// mov edi,3
// jmp ff8_en.528DDE
// mov edi,2
// push edi
// push esi
// call ff8_en.4A0700
// shl esi,4
// add esp,8
// mov eax,2
// mov word ptr ds:[esi+1D9CFA4],bx
// mov word ptr ds:[esi+1D9CFA6],di
// pop edi
// pop esi
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov eax,dword ptr ss:[esp+4]
// movsx ecx,byte ptr ds:[eax+184]
// mov edx,dword ptr ds:[eax+ecx*4]
// lea eax,dword ptr ds:[eax+ecx*4]
// push edx
// mov eax,dword ptr ds:[eax-4]
// push eax
// call ff8_en.49FBC0
// add esp,8
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// push edi
// mov edi,dword ptr ss:[esp+10]
// movsx eax,byte ptr ds:[edi+184]
// mov ebx,dword ptr ds:[edi+eax*4]
// mov esi,dword ptr ds:[edi+eax*4-4]
// lea eax,dword ptr ds:[edi+eax*4]
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.528E70
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov cl,byte ptr ds:[edi+174]
// mov al,byte ptr ds:[edi+175]
// mov edx,1
// shl edx,cl
// test al,dl
// je ff8_en.528EE3
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,1
// mov ecx,esi
// shl edx,cl
// test byte ptr ds:[eax+D3],dl
// je ff8_en.528EA6
// pop edi
// pop esi
// mov eax,5
// pop ebx
// ret 
// mov ecx,dword ptr ds:[1CE4778]
// push ebx
// push ecx
// call <ff8_en.sub_530750>
// push eax
// push esi
// call ff8_en.4A0410
// push esi
// call ff8_en.4A0620
// push esi
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,esi
// add esp,18
// shl dl,cl
// or byte ptr ds:[eax+D3],dl
// pop edi
// pop esi
// mov eax,1
// pop ebx
// ret 
// mov eax,1
// mov ecx,esi
// shl eax,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[ecx+D3],al
// jne ff8_en.528EDA
// mov al,byte ptr ds:[edi+184]
// add al,FE
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// mov eax,3
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// push ebx
// mov ebx,dword ptr ss:[esp+10]
// push esi
// push edi
// movsx eax,byte ptr ds:[ebx+184]
// mov edi,dword ptr ds:[ebx+eax*4]
// mov esi,dword ptr ds:[ebx+eax*4-4]
// lea eax,dword ptr ds:[ebx+eax*4]
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.528F53
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,1
// mov ecx,esi
// shl edx,cl
// test byte ptr ds:[eax+D3],dl
// je ff8_en.528F75
// pop edi
// pop esi
// mov eax,5
// pop ebx
// add esp,8
// ret 
// mov ecx,dword ptr ds:[1CE4778]
// push edi
// push ecx
// call <ff8_en.sub_530750>
// mov edi,eax
// push edi
// push esi
// call ff8_en.4A0410
// push esi
// call ff8_en.4A0620
// push esi
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,esi
// add esp,18
// shl dl,cl
// mov cl,byte ptr ds:[eax+D3]
// or cl,dl
// mov byte ptr ds:[eax+D3],cl
// mov cl,byte ptr ds:[eax+D4]
// or cl,dl
// mov dx,word ptr ss:[esp+C]
// mov byte ptr ds:[eax+D4],cl
// mov cl,byte ptr ds:[ebx+184]
// mov ax,word ptr ss:[esp+E]
// add cl,FE
// shl esi,4
// mov byte ptr ds:[ebx+184],cl
// mov cx,word ptr ss:[esp+10]
// mov dword ptr ds:[esi+1D9CFA0],edi
// mov word ptr ds:[esi+1D9CF98],dx
// mov dx,word ptr ss:[esp+12]
// mov word ptr ds:[esi+1D9CF9A],ax
// mov word ptr ds:[esi+1D9CF9C],cx
// mov word ptr ds:[esi+1D9CF9E],dx
// pop edi
// pop esi
// mov eax,3
// pop ebx
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,C
// push ebx
// push esi
// push edi
// mov edi,dword ptr ss:[esp+1C]
// movsx eax,byte ptr ds:[edi+184]
// mov cx,word ptr ds:[edi+eax*4-4]
// mov dx,word ptr ds:[edi+eax*4]
// mov esi,dword ptr ds:[edi+eax*4-C]
// mov ebx,dword ptr ds:[edi+eax*4-8]
// mov word ptr ss:[esp+C],cx
// mov word ptr ss:[esp+E],dx
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.529064
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov cl,byte ptr ds:[edi+174]
// mov eax,1
// shl eax,cl
// mov cl,byte ptr ds:[edi+175]
// mov edx,1
// test cl,al
// mov ecx,esi
// je ff8_en.5291AE
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// shl edx,cl
// test byte ptr ds:[eax+D3],dl
// je ff8_en.5290A1
// pop edi
// pop esi
// mov eax,5
// pop ebx
// add esp,C
// ret 
// mov ecx,dword ptr ds:[1CE4778]
// push ebx
// push ecx
// call <ff8_en.sub_530750>
// mov edi,eax
// push edi
// push esi
// call ff8_en.4A0410
// push edi
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+10]
// add esp,14
// mov word ptr ss:[esp+10],cx
// movsx edx,cx
// mov cx,word ptr ss:[esp+C]
// movsx ebx,cx
// sar eax,10
// add edx,ebx
// add eax,11
// cmp edx,130
// mov word ptr ss:[esp+12],ax
// jl ff8_en.5290F8
// mov edx,dword ptr ss:[esp+10]
// mov ecx,138
// sub ecx,edx
// mov word ptr ss:[esp+C],cx
// mov edx,8
// cmp cx,dx
// jge ff8_en.529107
// mov word ptr ss:[esp+C],dx
// movsx ecx,ax
// mov ax,word ptr ss:[esp+E]
// movsx ebx,ax
// add ecx,ebx
// cmp ecx,E0
// jl ff8_en.52912C
// mov ecx,dword ptr ss:[esp+12]
// mov eax,E0
// sub eax,ecx
// mov word ptr ss:[esp+E],ax
// cmp ax,dx
// jge ff8_en.529136
// mov word ptr ss:[esp+E],dx
// lea edx,dword ptr ss:[esp+C]
// push edx
// push esi
// call ff8_en.4A07A0
// push esi
// call ff8_en.4A0620
// push esi
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,esi
// add esp,10
// shl dl,cl
// mov cl,byte ptr ds:[eax+D3]
// or cl,dl
// shl esi,4
// mov byte ptr ds:[eax+D3],cl
// mov ax,word ptr ss:[esp+C]
// mov cx,word ptr ss:[esp+E]
// mov dx,word ptr ss:[esp+10]
// mov dword ptr ds:[esi+1D9CFA0],edi
// mov word ptr ds:[esi+1D9CF98],ax
// mov ax,word ptr ss:[esp+12]
// mov word ptr ds:[esi+1D9CF9A],cx
// mov word ptr ds:[esi+1D9CF9C],dx
// mov word ptr ds:[esi+1D9CF9E],ax
// pop edi
// pop esi
// mov eax,1
// pop ebx
// add esp,C
// ret 
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// shl edx,cl
// test byte ptr ds:[eax+D3],dl
// jne ff8_en.5291A2
// mov al,byte ptr ds:[edi+184]
// add al,FC
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// mov eax,3
// pop ebx
// add esp,C
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,C
// push ebx
// push esi
// push edi
// mov edi,dword ptr ss:[esp+1C]
// movsx eax,byte ptr ds:[edi+184]
// mov cx,word ptr ds:[edi+eax*4-4]
// mov dx,word ptr ds:[edi+eax*4]
// mov esi,dword ptr ds:[edi+eax*4-C]
// mov ebx,dword ptr ds:[edi+eax*4-8]
// mov word ptr ss:[esp+C],cx
// mov word ptr ss:[esp+E],dx
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.529224
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov eax,1
// mov ecx,esi
// shl eax,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[ecx+D3],al
// je ff8_en.529247
// pop edi
// pop esi
// mov eax,5
// pop ebx
// add esp,C
// ret 
// mov edx,dword ptr ds:[1CE4778]
// push ebp
// push ebx
// push edx
// call <ff8_en.sub_530750>
// mov ebx,eax
// push ebx
// push esi
// call ff8_en.4A0410
// push ebx
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+10]
// add esp,14
// mov word ptr ss:[esp+14],cx
// movsx edx,cx
// mov cx,word ptr ss:[esp+10]
// movsx ebp,cx
// sar eax,10
// add edx,ebp
// add eax,11
// cmp edx,130
// mov word ptr ss:[esp+16],ax
// jl ff8_en.52929F
// mov edx,dword ptr ss:[esp+14]
// mov ecx,138
// sub ecx,edx
// mov word ptr ss:[esp+10],cx
// mov edx,8
// cmp cx,dx
// jge ff8_en.5292AE
// mov word ptr ss:[esp+10],dx
// movsx ecx,ax
// mov ax,word ptr ss:[esp+12]
// movsx ebp,ax
// add ecx,ebp
// pop ebp
// cmp ecx,E0
// jl ff8_en.5292D4
// mov ecx,dword ptr ss:[esp+12]
// mov eax,E0
// sub eax,ecx
// mov word ptr ss:[esp+E],ax
// cmp ax,dx
// jge ff8_en.5292DE
// mov word ptr ss:[esp+E],dx
// lea edx,dword ptr ss:[esp+C]
// push edx
// push esi
// call ff8_en.4A07A0
// push esi
// call ff8_en.4A0620
// push esi
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,esi
// add esp,10
// shl dl,cl
// mov cl,byte ptr ds:[eax+D3]
// or cl,dl
// mov byte ptr ds:[eax+D3],cl
// mov cl,byte ptr ds:[eax+D4]
// or cl,dl
// mov byte ptr ds:[eax+D4],cl
// mov cl,byte ptr ds:[edi+184]
// mov ax,word ptr ss:[esp+C]
// mov dx,word ptr ss:[esp+10]
// add cl,FC
// shl esi,4
// mov byte ptr ds:[edi+184],cl
// mov cx,word ptr ss:[esp+E]
// mov dword ptr ds:[esi+1D9CFA0],ebx
// mov word ptr ds:[esi+1D9CF98],ax
// mov ax,word ptr ss:[esp+12]
// mov word ptr ds:[esi+1D9CF9A],cx
// mov word ptr ds:[esi+1D9CF9C],dx
// mov word ptr ds:[esi+1D9CF9E],ax
// pop edi
// pop esi
// mov eax,3
// pop ebx
// add esp,C
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,C
// mov eax,dword ptr ss:[esp+10]
// push esi
// push edi
// mov cl,byte ptr ds:[eax+184]
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ss:[esp+A],dx
// movsx edx,cl
// dec cl
// mov dx,word ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// mov word ptr ss:[esp+8],dx
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// mov esi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.5293EB
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov eax,1
// mov ecx,esi
// shl eax,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[ecx+D3],al
// je ff8_en.52940D
// pop edi
// mov eax,5
// pop esi
// add esp,C
// ret 
// mov edx,dword ptr ds:[1CE4778]
// push ebx
// push edi
// push edx
// call <ff8_en.sub_530750>
// mov edi,eax
// push edi
// push esi
// call ff8_en.4A0410
// push edi
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+10]
// add esp,14
// mov word ptr ss:[esp+10],cx
// movsx edx,cx
// mov cx,word ptr ss:[esp+C]
// movsx ebx,cx
// sar eax,10
// add edx,ebx
// add eax,11
// cmp edx,130
// mov word ptr ss:[esp+12],ax
// jl ff8_en.529465
// mov edx,dword ptr ss:[esp+10]
// mov ecx,138
// sub ecx,edx
// mov word ptr ss:[esp+C],cx
// mov edx,8
// cmp cx,dx
// jge ff8_en.529474
// mov word ptr ss:[esp+C],dx
// movsx ecx,ax
// mov ax,word ptr ss:[esp+E]
// movsx ebx,ax
// add ecx,ebx
// pop ebx
// cmp ecx,E0
// jl ff8_en.52949A
// mov ecx,dword ptr ss:[esp+E]
// mov eax,E0
// sub eax,ecx
// mov word ptr ss:[esp+A],ax
// cmp ax,dx
// jge ff8_en.5294A4
// mov word ptr ss:[esp+A],dx
// lea edx,dword ptr ss:[esp+8]
// push edx
// push esi
// call ff8_en.4A07A0
// push esi
// call ff8_en.4A0620
// push esi
// call ff8_en.49FD50
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,esi
// add esp,10
// shl dl,cl
// mov cl,byte ptr ds:[eax+D3]
// or cl,dl
// shl esi,4
// mov byte ptr ds:[eax+D3],cl
// mov ax,word ptr ss:[esp+8]
// mov cx,word ptr ss:[esp+A]
// mov dx,word ptr ss:[esp+C]
// mov dword ptr ds:[esi+1D9CFA0],edi
// mov word ptr ds:[esi+1D9CF98],ax
// mov ax,word ptr ss:[esp+E]
// mov word ptr ds:[esi+1D9CF9A],cx
// mov word ptr ds:[esi+1D9CF9C],dx
// mov word ptr ds:[esi+1D9CF9E],ax
// pop edi
// mov eax,2
// pop esi
// add esp,C
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// push ebx
// push ebp
// push esi
// mov esi,dword ptr ss:[esp+18]
// push edi
// movsx eax,byte ptr ds:[esi+184]
// mov ecx,dword ptr ds:[esi+eax*4-8]
// mov edx,dword ptr ds:[esi+eax*4-C]
// mov ebx,dword ptr ds:[esi+eax*4]
// mov ebp,dword ptr ds:[esi+eax*4-4]
// mov edi,dword ptr ds:[esi+eax*4-14]
// mov dword ptr ss:[esp+1C],ecx
// mov ecx,dword ptr ds:[esi+eax*4-10]
// mov dword ptr ss:[esp+10],edx
// mov dword ptr ss:[esp+14],ecx
// call ff8_en.49F5D0
// cmp edi,eax
// jl ff8_en.52956D
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov cl,byte ptr ds:[esi+174]
// mov al,byte ptr ds:[esi+175]
// mov edx,1
// shl edx,cl
// test al,dl
// je ff8_en.529622
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,1
// mov ecx,edi
// shl edx,cl
// test byte ptr ds:[eax+D2],dl
// je ff8_en.5295AB
// pop edi
// pop esi
// pop ebp
// mov eax,5
// pop ebx
// add esp,8
// ret 
// call ff8_en.49FD60
// mov ecx,dword ptr ss:[esp+1C]
// mov edx,dword ptr ss:[esp+10]
// push ebx
// mov dword ptr ds:[1D9CDC4],eax
// mov eax,dword ptr ss:[esp+18]
// push ebp
// push ecx
// mov ecx,dword ptr ds:[1CE4778]
// push edx
// push eax
// push ecx
// call <ff8_en.sub_530750>
// add esp,8
// push eax
// push edi
// call ff8_en.4A04E0
// push edi
// call ff8_en.4A0620
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,edi
// add esp,1C
// mov bl,byte ptr ds:[eax+D3]
// mov word ptr ds:[esi+204],0
// shl dl,cl
// pop edi
// pop esi
// pop ebp
// or bl,dl
// mov byte ptr ds:[eax+D3],bl
// mov cl,byte ptr ds:[eax+D2]
// or cl,dl
// pop ebx
// mov byte ptr ds:[eax+D2],cl
// mov eax,1
// add esp,8
// ret 
// movsx eax,word ptr ds:[esi+204]
// sub eax,0
// je ff8_en.529683
// dec eax
// jne ff8_en.5296AC
// push edi
// call ff8_en.49FBF0
// add esp,4
// test eax,eax
// jne ff8_en.5296AC
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,edi
// mov bl,byte ptr ds:[eax+D2]
// shl dl,cl
// not dl
// and bl,dl
// mov dl,byte ptr ds:[esi+184]
// mov byte ptr ds:[eax+D2],bl
// mov eax,dword ptr ds:[1D9CDC4]
// add dl,FA
// push eax
// mov byte ptr ds:[esi+184],dl
// call ff8_en.49FD50
// add esp,4
// mov eax,3
// pop edi
// pop esi
// pop ebp
// pop ebx
// add esp,8
// ret 
// push edi
// call ff8_en.49FD50
// push edi
// call ff8_en.49FD70
// add esp,8
// mov dword ptr ds:[esi+140],eax
// test eax,eax
// jl ff8_en.5296AC
// push edi
// call ff8_en.4A0660
// add esp,4
// inc word ptr ds:[esi+204]
// pop edi
// pop esi
// pop ebp
// mov eax,1
// pop ebx
// add esp,8
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,18
// push ebx
// push esi
// mov esi,dword ptr ss:[esp+24]
// push edi
// movsx eax,byte ptr ds:[esi+184]
// mov cx,word ptr ds:[esi+eax*4]
// mov dx,word ptr ds:[esi+eax*4-4]
// mov ebx,dword ptr ds:[esi+eax*4-18]
// mov edi,dword ptr ds:[esi+eax*4-1C]
// mov word ptr ss:[esp+1A],cx
// mov ecx,dword ptr ds:[esi+eax*4-8]
// mov word ptr ss:[esp+18],dx
// mov edx,dword ptr ds:[esi+eax*4-C]
// mov dword ptr ss:[esp+28],ecx
// mov ecx,dword ptr ds:[esi+eax*4-10]
// mov dword ptr ss:[esp+C],edx
// mov edx,dword ptr ds:[esi+eax*4-14]
// mov dword ptr ss:[esp+10],ecx
// mov dword ptr ss:[esp+14],edx
// call ff8_en.49F5D0
// cmp edi,eax
// jl ff8_en.529724
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov cl,byte ptr ds:[esi+174]
// mov eax,1
// shl eax,cl
// mov cl,byte ptr ds:[esi+175]
// test cl,al
// je ff8_en.529866
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,1
// mov ecx,edi
// shl edx,cl
// test byte ptr ds:[eax+D2],dl
// je ff8_en.529761
// pop edi
// pop esi
// mov eax,5
// pop ebx
// add esp,18
// ret 
// push ebp
// call ff8_en.49FD60
// mov ecx,dword ptr ds:[1CE4778]
// push ebx
// push ecx
// mov dword ptr ds:[1D9CDD0],eax
// call <ff8_en.sub_530750>
// mov ebx,eax
// push ebx
// call <ff8_en.sub_4A0EC0>
// lea ecx,dword ptr ds:[eax+30]
// add esp,C
// mov word ptr ss:[esp+20],cx
// movsx edx,cx
// mov cx,word ptr ss:[esp+1C]
// movsx ebp,cx
// sar eax,10
// add edx,ebp
// add eax,11
// cmp edx,130
// mov word ptr ss:[esp+22],ax
// jl ff8_en.5297BC
// mov edx,dword ptr ss:[esp+20]
// mov ecx,138
// sub ecx,edx
// mov word ptr ss:[esp+1C],cx
// mov edx,8
// cmp cx,dx
// jge ff8_en.5297CB
// mov word ptr ss:[esp+1C],dx
// movsx ecx,ax
// mov ax,word ptr ss:[esp+1E]
// movsx ebp,ax
// add ecx,ebp
// pop ebp
// cmp ecx,E0
// jl ff8_en.5297F1
// mov ecx,dword ptr ss:[esp+1E]
// mov eax,E0
// sub eax,ecx
// mov word ptr ss:[esp+1A],ax
// cmp ax,dx
// jge ff8_en.5297FB
// mov word ptr ss:[esp+1A],dx
// lea edx,dword ptr ss:[esp+18]
// push edx
// push edi
// call ff8_en.4A07A0
// mov eax,dword ptr ss:[esp+30]
// mov ecx,dword ptr ss:[esp+14]
// mov edx,dword ptr ss:[esp+18]
// push eax
// mov eax,dword ptr ss:[esp+20]
// push ecx
// push edx
// push eax
// push ebx
// push edi
// call ff8_en.4A04E0
// push edi
// call ff8_en.4A0620
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,edi
// add esp,24
// mov bl,byte ptr ds:[eax+D3]
// mov word ptr ds:[esi+204],0
// shl dl,cl
// pop edi
// pop esi
// or bl,dl
// mov byte ptr ds:[eax+D3],bl
// mov cl,byte ptr ds:[eax+D2]
// or cl,dl
// pop ebx
// mov byte ptr ds:[eax+D2],cl
// mov eax,1
// add esp,18
// ret 
// movsx eax,word ptr ds:[esi+204]
// sub eax,0
// je ff8_en.5298C6
// dec eax
// jne ff8_en.5298EF
// push edi
// call ff8_en.49FBF0
// add esp,4
// test eax,eax
// jne ff8_en.5298EF
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov dl,1
// mov ecx,edi
// mov bl,byte ptr ds:[eax+D2]
// shl dl,cl
// not dl
// and bl,dl
// mov dl,byte ptr ds:[esi+184]
// mov byte ptr ds:[eax+D2],bl
// mov eax,dword ptr ds:[1D9CDD0]
// add dl,F8
// push eax
// mov byte ptr ds:[esi+184],dl
// call ff8_en.49FD50
// add esp,4
// mov eax,3
// pop edi
// pop esi
// pop ebx
// add esp,18
// ret 
// push edi
// call ff8_en.49FD50
// push edi
// call ff8_en.49FD70
// add esp,8
// mov dword ptr ds:[esi+140],eax
// test eax,eax
// jl ff8_en.5298EF
// push edi
// call ff8_en.4A0660
// add esp,4
// inc word ptr ds:[esi+204]
// pop edi
// pop esi
// mov eax,1
// pop ebx
// add esp,18
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// push ebx
// push esi
// push edi
// mov edi,dword ptr ss:[esp+10]
// movsx eax,byte ptr ds:[edi+184]
// mov esi,dword ptr ds:[edi+eax*4]
// call ff8_en.49F5D0
// cmp esi,eax
// jl ff8_en.529929
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov ebx,1
// mov ecx,esi
// shl ebx,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// xor eax,eax
// mov al,byte ptr ds:[ecx+D4]
// and eax,ebx
// je ff8_en.5299BF
// test byte ptr ds:[ecx+D3],bl
// je ff8_en.5299BF
// test byte ptr ds:[1CE48B8],C0
// je ff8_en.529979
// push esi
// call ff8_en.4A06E0
// add esp,4
// test eax,eax
// je ff8_en.529979
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// test byte ptr ds:[ecx+D2],bl
// jne ff8_en.529979
// push esi
// call ff8_en.4A0660
// add esp,4
// push esi
// call ff8_en.49FBF0
// add esp,4
// test eax,eax
// jne ff8_en.5299E2
// push esi
// call ff8_en.4A06E0
// add esp,4
// test eax,eax
// je ff8_en.5299E2
// mov al,1
// mov ecx,esi
// shl al,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// mov bl,byte ptr ds:[ecx+D3]
// not al
// and bl,al
// mov byte ptr ds:[ecx+D3],bl
// mov dl,byte ptr ds:[ecx+D4]
// and dl,al
// mov byte ptr ds:[ecx+D4],dl
// jmp ff8_en.5299CB
// test eax,eax
// jne ff8_en.5299E2
// test byte ptr ds:[ecx+D3],bl
// jne ff8_en.5299E2
// mov al,byte ptr ds:[edi+184]
// dec al
// mov byte ptr ds:[edi+184],al
// pop edi
// pop esi
// mov eax,2
// pop ebx
// ret 
// pop edi
// pop esi
// mov eax,1
// pop ebx
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push edx
// call ff8_en.49FD50
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,C
// push esi
// mov esi,dword ptr ss:[esp+14]
// push edi
// movsx eax,byte ptr ds:[esi+184]
// mov edi,dword ptr ds:[esi+eax*4-10]
// call ff8_en.49F5D0
// cmp edi,eax
// jl ff8_en.529A4C
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// mov eax,dword ptr ds:[<&SG_FIELD_VARS>]
// mov edx,1
// mov ecx,edi
// shl edx,cl
// test byte ptr ds:[eax+D3],dl
// je ff8_en.529A6D
// pop edi
// mov eax,5
// pop esi
// add esp,C
// ret 
// movsx eax,byte ptr ds:[esi+184]
// push ebx
// push ebp
// mov bx,word ptr ds:[esi+eax*4]
// mov dx,word ptr ds:[esi+eax*4-4]
// mov cx,word ptr ds:[esi+eax*4-8]
// mov ax,word ptr ds:[esi+eax*4-C]
// mov word ptr ss:[esp+14],dx
// mov word ptr ss:[esp+16],bx
// movsx ebp,ax
// movsx edx,dx
// add ebp,edx
// mov word ptr ss:[esp+12],cx
// cmp ebp,130
// mov word ptr ss:[esp+10],ax
// jl ff8_en.529ABD
// mov edx,dword ptr ss:[esp+14]
// mov eax,138
// sub eax,edx
// mov word ptr ss:[esp+10],ax
// mov edx,8
// cmp ax,dx
// jge ff8_en.529ACC
// mov word ptr ss:[esp+10],dx
// movsx eax,cx
// movsx ebx,bx
// add eax,ebx
// pop ebp
// cmp eax,E0
// pop ebx
// jl ff8_en.529AED
// mov eax,dword ptr ss:[esp+E]
// mov ecx,E0
// sub ecx,eax
// mov word ptr ss:[esp+A],cx
// cmp cx,dx
// jge ff8_en.529AF7
// mov word ptr ss:[esp+A],dx
// lea ecx,dword ptr ss:[esp+8]
// push ecx
// push edi
// call ff8_en.4A07A0
// mov cl,byte ptr ds:[esi+184]
// mov dx,word ptr ss:[esp+10]
// add esp,8
// add cl,FB
// shl edi,4
// mov eax,edi
// mov byte ptr ds:[esi+184],cl
// mov cx,word ptr ss:[esp+A]
// pop edi
// mov dword ptr ds:[eax+1D9CFA0],0
// mov word ptr ds:[eax+1D9CF98],dx
// mov dx,word ptr ss:[esp+8]
// mov word ptr ds:[eax+1D9CF9A],cx
// mov cx,word ptr ss:[esp+A]
// mov word ptr ds:[eax+1D9CF9C],dx
// mov word ptr ds:[eax+1D9CF9E],cx
// mov eax,2
// pop esi
// add esp,C
// ret 
// nop 
// nop 
// push esi
// mov esi,dword ptr ss:[esp+8]
// push edi
// movsx eax,byte ptr ds:[esi+184]
// mov edi,dword ptr ds:[esi+eax*4]
// call ff8_en.49F5D0
// cmp edi,eax
// jl ff8_en.529B88
// push 388
// push 4D
// call <ff8_en.__initp_misc_winxfltr_2>
// add esp,8
// push edi
// call ff8_en.49FBF0
// add esp,4
// test eax,eax
// jne ff8_en.529BD5
// mov al,1
// mov ecx,edi
// shl al,cl
// mov ecx,dword ptr ds:[<&SG_FIELD_VARS>]
// pop edi
// mov dl,byte ptr ds:[ecx+D3]
// not al
// and dl,al
// mov byte ptr ds:[ecx+D3],dl
// mov dl,byte ptr ds:[ecx+D4]
// and dl,al
// mov al,byte ptr ds:[esi+184]
// dec al
// mov byte ptr ds:[ecx+D4],dl
// mov byte ptr ds:[esi+184],al
// mov eax,2
// pop esi
// ret 
// push edi
// call ff8_en.4A0660
// add esp,4
// mov eax,1
// pop edi
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// push esi
// push edi
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// movsx edx,al
// dec al
// push edi
// mov esi,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// push esi
// call ff8_en.4B7C90
// shl esi,4
// add esp,8
// mov eax,2
// mov word ptr ds:[esi+1D9CF5C],di
// pop edi
// pop esi
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,C
// mov eax,dword ptr ss:[esp+10]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push edi
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebx
// mov ebp,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebp
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov dword ptr ss:[esp+24],edx
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+20],esi
// movsx esi,cl
// dec cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+1C],esi
// movsx esi,cl
// dec cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov ax,word ptr ss:[esp+1C]
// mov cx,word ptr ss:[esp+20]
// mov word ptr ss:[esp+2C],ax
// mov word ptr ss:[esp+2E],cx
// lea eax,dword ptr ss:[esp+2C]
// mov ecx,esi
// push eax
// and ecx,1
// push edx
// push ecx
// call ff8_en.4B7D00
// mov dx,word ptr ss:[esp+28]
// mov cx,word ptr ss:[esp+2C]
// add esp,18
// shl esi,4
// mov eax,esi
// mov word ptr ds:[eax+1D9CF58],1
// mov word ptr ds:[eax+1D9CF66],dx
// mov dx,word ptr ss:[esp+18]
// mov word ptr ds:[eax+1D9CF64],cx
// mov word ptr ds:[eax+1D9CF62],dx
// mov word ptr ds:[eax+1D9CF60],bp
// mov word ptr ds:[eax+1D9CF5E],bx
// mov word ptr ds:[eax+1D9CF5C],di
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// add esp,C
// ret 
// nop 
// nop 
// sub esp,10
// mov eax,dword ptr ss:[esp+14]
// push ebx
// push ebp
// push esi
// mov cl,byte ptr ds:[eax+184]
// push edi
// movsx edx,cl
// dec cl
// mov edi,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push edi
// mov ebx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebx
// mov ebp,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx edx,cl
// dec cl
// push ebp
// mov edx,dword ptr ds:[eax+edx*4]
// mov byte ptr ds:[eax+184],cl
// movsx esi,cl
// dec cl
// mov dword ptr ss:[esp+28],edx
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+24],esi
// push edx
// movsx esi,cl
// dec cl
// lea edx,dword ptr ss:[esp+34]
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+24],esi
// push edx
// movsx esi,cl
// dec cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov dword ptr ss:[esp+24],esi
// movsx esi,cl
// dec cl
// mov esi,dword ptr ds:[eax+esi*4]
// mov byte ptr ds:[eax+184],cl
// mov cx,word ptr ss:[esp+28]
// mov ax,word ptr ss:[esp+24]
// mov word ptr ss:[esp+3A],cx
// mov word ptr ss:[esp+38],ax
// mov eax,dword ptr ss:[esp+2C]
// mov ecx,esi
// and ecx,1
// push eax
// push ecx
// call ff8_en.4B7D70
// mov dx,word ptr ss:[esp+2C]
// mov cx,word ptr ss:[esp+30]
// add esp,1C
// shl esi,4
// mov eax,esi
// mov word ptr ds:[eax+1D9CF58],2
// mov word ptr ds:[eax+1D9CF66],dx
// mov dx,word ptr ss:[esp+18]
// mov word ptr ds:[eax+1D9CF64],cx
// mov cx,word ptr ss:[esp+1C]
// mov word ptr ds:[eax+1D9CF62],dx
// mov word ptr ds:[eax+1D9CF60],cx
// mov word ptr ds:[eax+1D9CF5E],bp
// mov word ptr ds:[eax+1D9CF5C],bx
// mov word ptr ds:[eax+1D9CF5A],di
// pop edi
// pop esi
// pop ebp
// mov eax,2
// pop ebx
// add esp,10
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,edx
// push edx
// shl eax,4
// mov word ptr ds:[eax+1D9CF58],0
// call ff8_en.4B7C70
// add esp,4
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// test edx,edx
// je ff8_en.529ED7
// call ff8_en.56DAC0
// mov eax,2
// ret 
// call ff8_en.56DAD0
// mov eax,2
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// sub esp,8
// mov ecx,dword ptr ss:[esp+C]
// mov word ptr ss:[esp+2],0
// mov word ptr ss:[esp+4],CF
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,edx
// sub eax,0
// je ff8_en.529F38
// dec eax
// je ff8_en.529F2F
// dec eax
// jne ff8_en.529F3F
// mov word ptr ss:[esp],FFE0
// jmp ff8_en.529F3F
// mov word ptr ss:[esp],20
// jmp ff8_en.529F3F
// mov word ptr ss:[esp],0
// lea eax,dword ptr ss:[esp]
// push 1E
// xor edx,edx
// push eax
// mov dl,byte ptr ds:[ecx+256]
// push 1
// push 30
// push edx
// call ff8_en.532180
// mov eax,2
// add esp,1C
// ret 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// nop 
// mov ecx,dword ptr ss:[esp+4]
// sub esp,8
// mov al,byte ptr ds:[ecx+184]
// movsx edx,al
// dec al
// mov edx,dword ptr ds:[ecx+edx*4]
// mov byte ptr ds:[ecx+184],al
// mov eax,edx
// xor edx,edx
// sub eax,edx
// je ff8_en.529FAB
// dec eax
// je ff8_en.529FA2
// dec eax
// jne ff8_en.529FB0
// mov word ptr ss:[esp],FFE0
// jmp ff8_en.529FB0
// mov word ptr ss:[esp],20
// jmp ff8_en.529FB0
// mov word ptr ss:[esp],dx
// mov eax,dword ptr ss:[esp]
// mov word ptr ss:[esp+2],dx
// neg eax
// mov word ptr ss:[esp],ax
// lea edx,dword ptr ss:[esp]
// push 1E
// xor eax,eax
// mov al,byte ptr ds:[ecx+256]
// push edx
// push 1
// push 30
// push eax
// mov word ptr ss:[esp+18],FF31
// call ff8_en.532180
// mov eax,2
// add esp,1C
// ret 
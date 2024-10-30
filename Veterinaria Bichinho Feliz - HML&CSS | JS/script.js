let pets = [];
let nextId = 10;

class Pet {
    constructor(id, nome, gravidade){
        this.id = id;
        this.nome = nome;
        this.gravidade = gravidade;
    }
}

function cadastroPet(nome, gravidade){
    let pet = new Pet(nextId++, nome, gravidade);
    pets.push(pet);
    return pet;
}

function imprimeTabela(){
    let tabela = document.getElementById('tabelaPets');
    tabela.innerHTML = `<tr>
        <th>SENHA</th>
        <th>NOME</th>
        <th>GRAVIDADE</th>
    </tr>`; // Limpa e redefine a tabela com cabeçalhos

    pets.forEach(pet =>{
        let row = tabela.insertRow();
        row.insertCell(0).innerHTML = pet.id;
        row.insertCell(1).innerHTML = pet.nome;
        row.insertCell(2).innerHTML = gravidadeParaTexto(pet.gravidade);
    });
}

function imprimeTabelaOrdenada(){
    let sortedPets = [...pets].sort((a, b) => b.gravidade - a.gravidade);

    let tabela = document.getElementById('tabelaPetsOrdenada');
    tabela.innerHTML = `<tr>
        <th>SENHA</th>
        <th>NOME</th>
        <th>GRAVIDADE</th>
    </tr>`; // Limpa e redefine a tabela com cabeçalhos

    sortedPets.forEach(pet =>{
        let row = tabela.insertRow();
        row.insertCell(0).innerHTML = pet.id;
        row.insertCell(1).innerHTML = pet.nome;
        row.insertCell(2).innerHTML = gravidadeParaTexto(pet.gravidade);
    });
}

function gravidadeParaTexto(gravidade){
    switch (gravidade) {
        case 1:
            return "Leve";
        case 2:
            return "Média";
        case 3:
            return "Grave";
        case 4:
            return "Gravíssima";
        default:
            return "Desconhecido";
    }
}

function adicionarPet(){
    let nome = document.getElementById("nome").value;
    let gravidade = parseInt(document.getElementById("gravidade").value);

    if (nome && gravidade) {
        cadastroPet(nome, gravidade);
        imprimeTabela();
        imprimeTabelaOrdenada();
    } else {
        alert("Preencha todos os campos!");
    }
}

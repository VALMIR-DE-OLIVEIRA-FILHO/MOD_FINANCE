# 🏗️ Arquitetura do Projeto MOD_FINANCE

## Visão Geral

MOD_FINANCE é um sistema de gerenciamento financeiro desenvolvido em PHP que permite registrar, filtrar e analisar lançamentos (entradas e saídas) com funcionalidades de auditoria através do gerenciador de consultas.

---

## 📊 Diagrama de Classes

```
┌──────────────────────────────────────┐
│          Lancamento                  │
├──────────────────────────────────────┤
│ Atributos:                           │
│  + id: string                        │
│  + descricao: string                 │
│  + valor: float                      │
│  + tipo: string (entrada|saida)      │
│  + data: string (YYYY-MM-DD)         │
├──────────────────────────────────────┤
│ Métodos:                             │
│  + __construct()                     │
│  + toLine(): string                  │
│  + fromLine(linha): Lancamento       │
└──────────────────────────────────────┘
            △
            │ criado por
            │
┌──────────────────────────────────────┐
│    LancamentoManager                 │
├──────────────────────────────────────┤
│ Atributos:                           │
│  - file: string (caminho do arquivo) │
├──────────────────────────────────────┤
│ Métodos:                             │
│  + __construct(filePath: string)     │
│  + listar(): Lancamento[]            │
│  + adicionar(l: Lancamento): void    │
│  + limpar(): void                    │
│                                      │
│ Responsabilidades:                   │
│  • Gerenciar persistência de dados   │
│  • Ler/escrever arquivo de lançamentos│
│  • Criar instâncias de Lancamento    │
└──────────────────────────────────────┘

┌──────────────────────────────────────┐
│    ConsultaManager                   │
├──────────────────────────────────────┤
│ Atributos:                           │
│  - arquivoConsultas: string          │
│  - arquivoFuncionarios: string       │
├──────────────────────────────────────┤
│ Métodos:                             │
│  + __construct(cons, func): void     │
│  + getIdColaborador(nome): string    │
│  + registrarConsulta(): void         │
│    (nomeUsuario, inicio, fim, tipo)  │
│                                      │
│ Responsabilidades:                   │
│  • Registrar auditoria de consultas  │
│  • Mapear colaboradores              │
│  • Persistir histórico de filtros    │
└──────────────────────────────────────┘
```

---

## 🔄 Fluxo de Interação

```
┌─────────────┐
│   Usuário   │
└──────┬──────┘
       │
       ▼
┌──────────────────────┐
│    index.php         │ (Interface Web)
│  - Exibe formulários │
│  - Aplica filtros    │
│  - Mostra relatórios │
└──────┬───────────────┘
       │
       ├──────────────────┬──────────────────┐
       ▼                  ▼                  ▼
┌─────────────┐   ┌────────────────┐   ┌─────────────┐
│ LancamentoM │   │  ConsultaM     │   │  salvar.php │
│   anager    │   │  anager        │   │  limpar.php │
└──────┬──────┘   └────────┬───────┘   └──────┬──────┘
       │                   │                   │
       ├───────────────────┼───────────────────┤
       ▼                   ▼                   ▼
┌──────────────────────────────────────────────────┐
│         data/ (Persistência)                     │
│  • lancamentos.txt                               │
│  • consultas.txt                                 │
│  • funcionarios.txt                              │
└──────────────────────────────────────────────────┘
```

---

## 📝 Descrição Detalhada das Classes

### 1. **Lancamento**

**Propósito:** Representar um registro individual de entrada ou saída financeira.

**Atributos:**

| Atributo      | Tipo   | Descrição                                 |
| ------------- | ------ | ------------------------------------------- |
| `id`        | string | Identificador único do lançamento         |
| `descricao` | string | Descrição do lançamento (ex: "Salário") |
| `valor`     | float  | Valor em reais                              |
| `tipo`      | string | "entrada" ou "saida"                        |
| `data`      | string | Data no formato YYYY-MM-DD                  |

**Métodos:**

```php
// Construtor
public function __construct($id, $descricao, $valor, $tipo, $data)
// Converte para formato de linha (serialização)
public function toLine(): string
// Cria instância a partir de linha de arquivo
public static function fromLine($line): Lancamento
```

**Exemplo de Uso:**

```php
$lancamento = new Lancamento(
    "001",
    "Salário Mensal",
    3000.00,
    "entrada",
    "2024-12-01"
);
echo $lancamento->toLine(); 
// Saída: 001|Salário Mensal|3000|entrada|2024-12-01
```

---

### 2. **LancamentoManager**

**Propósito:** Gerenciar a persistência e recuperação de lançamentos em arquivo.

**Atributos:**

| Atributo | Tipo   | Descrição                         |
| -------- | ------ | ----------------------------------- |
| `file` | string | Caminho do arquivo de armazenamento |

**Métodos:**

```php
// Inicializa o gerenciador e cria arquivo se não existir
public function __construct($filePath)

// Retorna array com todos os lançamentos do arquivo
public function listar(): array

// Adiciona novo lançamento ao final do arquivo
public function adicionar(Lancamento $l): void

// Limpa completamente o arquivo
public function limpar(): void
```

**Fluxo de Funcionamento:**

1. Construtor verifica se arquivo existe, caso contrário cria vazio
2. `listar()` lê arquivo linha por linha e reconstrói objetos Lancamento
3. `adicionar()` serializa Lancamento e escreve no final do arquivo
4. `limpar()` remove todo conteúdo

**Exemplo:**

```php
$manager = new LancamentoManager("data/lancamentos.txt");
$lancamentos = $manager->listar(); // Array de Lancamento

$novo = new Lancamento("002", "Venda", 500, "entrada", "2024-12-02");
$manager->adicionar($novo);
```

---

### 3. **ConsultaManager**

**Propósito:** Registrar auditoria de consultas e mapear colaboradores.

**Atributos:**

| Atributo                | Tipo   | Descrição                             |
| ----------------------- | ------ | --------------------------------------- |
| `arquivoConsultas`    | string | Arquivo onde consultas são registradas |
| `arquivoFuncionarios` | string | Arquivo com dados de colaboradores      |

**Métodos:**

```php
// Inicializa gerenciador
public function __construct($arquivoConsultas, $arquivoFuncionarios)

// Busca ID do colaborador pelo nome
// Retorna "desconhecido" se não encontrar
public function getIdColaborador($nome): string

// Registra uma consulta com timestamp
public function registrarConsulta($nomeUsuario, $inicio, $fim, $tipo): void
```

**Fluxo de Funcionamento:**

1. `getIdColaborador()` busca no arquivo de funcionários por nome (case-insensitive)
2. `registrarConsulta()` cria registro com ID único (uniqid), ID do colaborador, filtros e timestamp
3. Formato do registro: `IDConsulta|IDColaborador|DataInicio|DataFim|Tipo|DataHora`

**Arquivo de Funcionários (esperado):**

```
Nome;Cargo;ID
João Silva;Gerente;100
Maria Santos;Analista;101
```

**Exemplo:**

```php
$consultas = new ConsultaManager(
    "data/consultas.txt",
    "data/funcionarios.txt"
);

$id = $consultas->getIdColaborador("João Silva"); // "100"
$consultas->registrarConsulta("João Silva", "2024-01-01", "2024-12-31", "entrada");
```

---

## 🔗 Relacionamentos entre Classes

```
┌────────────────────────┐
│   index.php            │
│  (Controller/View)     │
└────────────┬───────────┘
             │
             ├─ instancia ─► LancamentoManager
             │
             ├─ instancia ─► ConsultaManager
             │
             ├─ trabalha com ─► Lancamento[]
             │
             └─ persiste em ─► data/

┌────────────────────────┐
│   salvar.php           │
│  (Insert Handler)      │
└────────────┬───────────┘
             │
             └─ instancia ─► LancamentoManager
                             + adiciona Lancamento

┌────────────────────────┐
│   limpar.php           │
│  (Delete Handler)      │
└────────────┬───────────┘
             │
             └─ instancia ─► LancamentoManager
                             + limpar()
```

---

## 📂 Estrutura de Dados (Arquivos)

### `data/lancamentos.txt`

**Formato:** Uma entrada por linha

```
001|Salário|3000|entrada|2024-12-01
002|Aluguel|1500|saida|2024-12-05
003|Venda|800|entrada|2024-12-10
```

### `data/consultas.txt`

**Formato:** Uma consulta por linha

```
C65a1b2c3|100|2024-01-01|2024-12-31|entrada|2024-12-01 14:30:25
C65a1b4d5|101|2024-11-01||saida|2024-12-02 09:15:10
```

### `data/funcionarios.txt`

**Formato:** Dados separados por ponto-e-vírgula

```
João Silva;Gerente;100
Maria Santos;Analista;101
```

---

## 🎯 Padrões de Design Utilizados

| Padrão                          | Classe                             | Descrição                                 |
| -------------------------------- | ---------------------------------- | ------------------------------------------- |
| **Manager**                | LancamentoManager, ConsultaManager | Centraliza operações de um domínio       |
| **Model**                  | Lancamento                         | Representa entidade do domínio             |
| **Serialization**          | Lancamento                         | Métodos toLine/fromLine para persistência |
| **File-based Persistence** | Manager classes                    | Armazenamento em arquivos de texto          |

---

## 🔐 Considerações de Segurança e Performance

### Segurança

- ⚠️ Sem validação de entrada nos filtros
- ⚠️ Arquivo de funcionários não validado
- ✅ Strings escapadas apenas na serialização

### Performance

- ⚠️ Carrega todo arquivo em memória ao listar()
- ⚠️ Busca linear em arquivo de funcionários
- ⚠️ Sem índices ou cache

**Recomendações:**

1. Migrar para banco de dados (MySQL, SQLite)
2. Adicionar validação com PHP Filter functions
3. Implementar autenticação e autorização
4. Adicionar tratamento de exceções

---

## 📋 Fluxo da Página Principal (index.php)

```
1. Carrega LancamentoManager
2. Obtém lista de lançamentos
3. Aplica filtros:
   - Data início/fim
   - Tipo (entrada/saida)
4. Calcula totalizações:
   - Total Entradas
   - Total Saídas
   - Lucro (Entradas - Saídas)
5. Se houver filtro E nome de usuário:
   - Registra consulta via ConsultaManager
6. Renderiza interface HTML com Bootstrap
7. Exibe:
   - Cards de resumo financeiro
   - Formulário de filtros
   - Formulário para novo lançamento
   - Tabela de lançamentos filtrados
   - Botão para limpar dados
```

---

## 🚀 Fluxos de Caso de Uso

### Caso 1: Adicionar Novo Lançamento

```
Usuário preenche formulário (index.php)
           ↓
Submete para salvar.php
           ↓
POST recebe: descricao, valor, tipo, data
           ↓
salvar.php cria Lancamento com ID gerado
           ↓
LancamentoManager.adicionar()
           ↓
Serializa com toLine() e escreve em arquivo
           ↓
Redireciona para index.php
```

### Caso 2: Filtrar Lançamentos com Auditoria

```
Usuário preenche filtros (inicio, fim, tipo) + nome
           ↓
Aplica GET em index.php
           ↓
LancamentoManager.listar() retorna todos
           ↓
array_filter() aplicada com função filtrar()
           ↓
Se tem filtro E nome:
  ConsultaManager.registrarConsulta()
           ↓
Exibe lançamentos filtrados
```

### Caso 3: Limpar Todos os Dados

```
Usuário clica em "Limpar Arquivo"
           ↓
Acessa limpar.php
           ↓
LancamentoManager.limpar()
           ↓
file_put_contents com string vazia
           ↓
Arquivo fica vazio
```

---

## 🔄 Sequência Típica de Execução

```
REQUEST (GET/POST)
    ↓
[Carrega arquivos de classe]
    ↓
[Instancia LancamentoManager]
    ↓
[Lê arquivo de lançamentos]
    ↓
[Aplica filtros]
    ↓
[Calcula totalizações]
    ↓
[Se necessário: registra consulta]
    ↓
[Renderiza HTML]
    ↓
RESPONSE (HTML)
```

---

## Integrantes : Valmir de Oliveira Filho, Bruno Mengue 

## 📌 Versão e Data

**Versão:** 1.0
**Última atualização:** 1 de dezembro de 2025
**Arquitetura gerada para:** techERP

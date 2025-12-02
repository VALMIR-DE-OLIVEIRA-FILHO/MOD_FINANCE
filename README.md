# MOD_FINANCE

Sistema simples de gerenciamento financeiro em PHP para registrar lançamentos (entradas e saídas), aplicar filtros e gerar relatórios básicos. O projeto utiliza persistência baseada em arquivos na pasta `data/`.

## Estrutura do Projeto

```
.
├── index.php
├── salvar.php
├── limpar.php
├── arquitetura.md
├── README.md
├── classes/
│   ├── ConsultaManager.php
│   ├── Lancamento.php
│   └── LancamentoManager.php
└── data/
    ├── consultas.txt
    ├── funcionarios.txt
    └── lancamentos.txt
```

## Funcionalidades

- Adicionar lançamentos (entrada/saída)
- Listar e filtrar lançamentos por data e tipo
- Calcular total de entradas, saídas e lucro
- Registrar consultas (auditoria) com mapa de colaboradores
- Limpar arquivo de lançamentos

## Como executar

1. Configure um servidor PHP (ex.: XAMPP, WAMP, PHP embutido).
2. Garanta permissões de escrita na pasta `data/`.
3. Acesse `index.php` via navegador.

Exemplo de comando com o servidor PHP embutido (na raiz do projeto):

```cmd
php -S localhost:8000
```

Em seguida, abra `http://localhost:8000` no navegador.

## Formato dos arquivos de dados

- `data/lancamentos.txt`: cada linha no formato `id|descricao|valor|tipo|data`
- `data/consultas.txt`: cada linha no formato `idConsulta|idColaborador|inicio|fim|tipo|timestamp`
- `data/funcionarios.txt`: cada linha no formato `Nome;Cargo;ID`

## Requisitos

- PHP 7.0+
- Permissões de leitura/gravação na pasta `data/`

## Recomendações

- Migrar para banco de dados (SQLite/MySQL) para ambientes com mais dados
- Validar entradas do usuário
- Implementar autenticação para rastrear usuário com segurança

## Autores

- Valmir de Oliveira Filho
- Bruno Mengue

## Licença

Projeto de exemplo — ajuste a licença conforme necessário.

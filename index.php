<?php
require_once "classes/LancamentoManager.php";
require_once "classes/ConsultaManager.php";

$manager = new LancamentoManager("data/lancamentos.txt");
$lancamentos = $manager->listar();

// filtros
$inicio = $_GET["inicio"] ?? "";
$fim = $_GET["fim"] ?? "";
$tipoFiltro = $_GET["tipo"] ?? "todos";
$usuario = $_GET["usuario"] ?? "";

// função de filtro
function filtrar($l, $inicio, $fim, $tipoFiltro) {
    if ($inicio && $l->data < $inicio) return false;
    if ($fim && $l->data > $fim) return false;
    if ($tipoFiltro !== "todos" && $l->tipo !== $tipoFiltro) return false;
    return true;
}

// aplicar filtros
$lancamentos = array_filter($lancamentos, fn($l) =>
    filtrar($l, $inicio, $fim, $tipoFiltro)
);

// Criar gerenciador de consulta
$consultaManager = new ConsultaManager(
    "data/consultas.txt",
    "data/funcionarios.txt"
);

// Registrar consulta somente se tiver filtro E nome
if (
    ($inicio != "" || $fim != "" || $tipoFiltro != "todos")
    && !empty($usuario)
) {
    $consultaManager->registrarConsulta($usuario, $inicio, $fim, $tipoFiltro);
}

// Cálculos
$totalEntrada = 0;
$totalSaida = 0;

foreach ($lancamentos as $l) {
    if ($l->tipo === "entrada") {
        $totalEntrada += $l->valor;
    } else {
        $totalSaida += $l->valor;
    }
}

$lucro = $totalEntrada - $totalSaida;
?>

<!DOCTYPE html>
<html>
<head>
    <title>TECHERP</title>

    <!-- BOOTSTRAP -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">

    <style>
        body {
            background: #f0f2f5;
        }

        .card {
            border: none;
            border-radius: 12px;
            box-shadow: 0 4px 12px rgba(0,0,0,0.08);
        }

        .btn-purple {
            background: #6f42c1;
            color: white;
        }
        .btn-purple:hover {
            background: #5933a6;
            color: white;
        }

        .table-dark {
            border-radius: 10px;
            overflow: hidden;
        }

        h2 {
            font-weight: 700;
        }
    </style>
</head>

<body class="container py-4">

<h2 class="text-center mb-4">tchERP</h2>

<!-- CARDS RESUMO -->
<div class="row g-4">
    <div class="col-md-4">
        <div class="card p-3 bg-light">
            <h6 class="text-muted">Total de Entradas</h6>
            <h2 class="text-success fw-bold">
                R$ <?= number_format($totalEntrada,2,",",".") ?>
            </h2>
        </div>
    </div>

    <div class="col-md-4">
        <div class="card p-3 bg-light">
            <h6 class="text-muted">Total de Saídas</h6>
            <h2 class="text-danger fw-bold">
                R$ <?= number_format($totalSaida,2,",",".") ?>
            </h2>
        </div>
    </div>

    <div class="col-md-4">
        <div class="card p-3 bg-light">
            <h6 class="text-muted">Lucro Líquido</h6>
            <h2 class="text-info fw-bold">
                R$ <?= number_format($lucro,2,",",".") ?>
            </h2>
        </div>
    </div>
</div>

<hr class="border-secondary my-4">

<!-- FILTROS -->
<div class="card p-4 mb-4">
    <h5 class="fw-bold mb-3">Filtros de Pesquisa</h5>

    <form method="GET" class="row g-3">

        <div class="col-md-3">
            <label class="fw-semibold">Seu nome (opcional)</label>
            <input type="text" name="usuario" value="<?= $usuario ?>" class="form-control" placeholder="Opcional">
        </div>

        <div class="col-md-3">
            <label class="fw-semibold">Data início</label>
            <input type="date" name="inicio" value="<?= $inicio ?>" class="form-control">
        </div>

        <div class="col-md-3">
            <label class="fw-semibold">Data fim</label>
            <input type="date" name="fim" value="<?= $fim ?>" class="form-control">
        </div>

        <div class="col-md-3">
            <label class="fw-semibold">Tipo</label>
            <select name="tipo" class="form-control">
                <option value="todos">Todos</option>
                <option value="entrada" <?= $tipoFiltro=="entrada"?"selected":"" ?>>Entrada</option>
                <option value="saida" <?= $tipoFiltro=="saida"?"selected":"" ?>>Saída</option>
            </select>
        </div>

        <div class="col-md-12 d-flex align-items-end">
            <button class="btn btn-purple w-100 mt-2">Aplicar Filtros</button>
        </div>

    </form>
</div>

<div class="row g-4">

    <!-- FORMULÁRIO -->
    <div class="col-md-4">
        <div class="card p-4">
            <h5 class="fw-bold">Novo Lançamento</h5>

            <form action="salvar.php" method="POST" class="mt-3">

                <label class="fw-semibold mt-2">Descrição</label>
                <input class="form-control" name="descricao" required>

                <label class="fw-semibold mt-2">Valor</label>
                <input class="form-control" type="number" step="0.01" name="valor" required>

                <label class="fw-semibold mt-2">Tipo</label>
                <select class="form-control" name="tipo" required>
                    <option value="entrada">Entrada</option>
                    <option value="saida">Saída</option>
                </select>

                <label class="fw-semibold mt-2">Data</label>
                <input class="form-control" type="date" name="data" required>

                <button class="btn btn-purple w-100 mt-3">Adicionar</button>
            </form>
        </div>
    </div>

    <!-- LISTA -->
    <div class="col-md-8">
        <div class="card p-4">

            <h5 class="fw-bold">Lançamentos</h5>

            <table class="table table-dark table-striped mt-3">
                <thead>
                    <tr>
                        <th>ID</th>
                        <th>Descrição</th>
                        <th>Valor</th>
                        <th>Tipo</th>
                        <th>Data</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($lancamentos as $l): ?>
                    <tr>
                        <td><?= $l->id ?></td>
                        <td><?= $l->descricao ?></td>
                        <td>R$ <?= number_format($l->valor,2,",",".") ?></td>
                        <td><?= ucfirst($l->tipo) ?></td>
                        <td><?= $l->data ?></td>
                    </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>

        </div>
    </div>
</div>

<div class="text-center mt-4">
    <a href="limpar.php" class="btn btn-danger px-4 py-2">Limpar Arquivo</a>
</div>

</body>
</html>
